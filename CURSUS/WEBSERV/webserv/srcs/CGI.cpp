#include "CGI.hpp"
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <limits.h>
#include <iomanip>

CGI::CGI(const Request& req, const LocationConfig& loc, const ServerConfig& cfg, int port) 
    : request(req), location(loc), config(cfg), server_port(port) {}

std::pair<std::string, int> CGI::execute(const std::string& script_path) {
    std::cerr << "DEBUG: Attempting to execute CGI for script: " << script_path << std::endl;

    // Extraer la extensión del script
    std::string extension = script_path.substr(script_path.find_last_of("."));
    std::map<std::string, std::string>::const_iterator it = location.cgi_paths.find(extension);
    if (it == location.cgi_paths.end()) {
        std::cerr << "ERROR: No CGI interpreter found for extension: " << extension << std::endl;
        return std::make_pair("<html><body><h1>500 Internal Server Error - No CGI Interpreter for Extension " + extension + "</h1></body></html>", 500);
    }
    std::string cgi_interpreter = it->second;
    std::cerr << "DEBUG: Using CGI interpreter: " << cgi_interpreter << std::endl;

    // Verificar que el intérprete exista y sea ejecutable
    if (access(cgi_interpreter.c_str(), X_OK) != 0) {
        std::cerr << "ERROR: CGI interpreter not found or not executable: " << cgi_interpreter 
                  << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl;
        return std::make_pair("<html><body><h1>500 Internal Server Error - Invalid CGI Interpreter</h1></body></html>", 500);
    }

    // Verificar que el script exista y sea ejecutable
    if (access(script_path.c_str(), X_OK) != 0) {
        std::cerr << "ERROR: CGI script not executable: " << script_path 
                  << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl;
        return std::make_pair("<html><body><h1>500 Internal Server Error - Script Not Executable</h1></body></html>", 500);
    }

    // Crear pipes para stdout, stderr y stdin
    int pipefd_out[2];
    int pipefd_err[2];
    int pipefd_in[2];
    if (pipe(pipefd_out) == -1 || pipe(pipefd_err) == -1 || pipe(pipefd_in) == -1) {
        std::cerr << "ERROR: Pipe creation failed, errno: " << errno << " (" << strerror(errno) << ")" << std::endl;
        if (pipefd_out[0] >= 0) close(pipefd_out[0]);
        if (pipefd_out[1] >= 0) close(pipefd_out[1]);
        if (pipefd_err[0] >= 0) close(pipefd_err[0]);
        if (pipefd_err[1] >= 0) close(pipefd_err[1]);
        if (pipefd_in[0] >= 0) close(pipefd_in[0]);
        if (pipefd_in[1] >= 0) close(pipefd_in[1]);
        return std::make_pair("<html><body><h1>500 Internal Server Error - Pipe Failure</h1></body></html>", 500);
    }

    // Crear proceso hijo
    pid_t pid = fork();
    if (pid == -1) {
        std::cerr << "ERROR: Fork failed, errno: " << errno << " (" << strerror(errno) << ")" << std::endl;
        close(pipefd_out[0]);
        close(pipefd_out[1]);
        close(pipefd_err[0]);
        close(pipefd_err[1]);
        close(pipefd_in[0]);
        close(pipefd_in[1]);
        return std::make_pair("<html><body><h1>500 Internal Server Error - Fork Failure</h1></body></html>", 500);
    }

    if (pid == 0) {
        // Proceso hijo
        close(pipefd_out[0]);
        close(pipefd_err[0]);
        close(pipefd_in[1]);
        dup2(pipefd_out[1], STDOUT_FILENO);
        dup2(pipefd_err[1], STDERR_FILENO);
        dup2(pipefd_in[0], STDIN_FILENO);
        close(pipefd_out[1]);
        close(pipefd_err[1]);
        close(pipefd_in[0]);

        // Configurar variables de entorno
        std::vector<std::string> env_vars;
        env_vars.push_back("REQUEST_METHOD=" + request.getMethod());
        char absolute_path[PATH_MAX] = {0};
        if (realpath(script_path.c_str(), absolute_path) == NULL) {
            std::cerr << "ERROR: realpath failed for script: " << script_path 
                      << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl;
            _exit(1);
        }
        env_vars.push_back("SCRIPT_FILENAME=" + std::string(absolute_path));
        env_vars.push_back("SCRIPT_NAME=" + request.getUri());
        env_vars.push_back("PATH_INFO=" + request.getUri());
        env_vars.push_back("SERVER_PROTOCOL=HTTP/1.1");
        env_vars.push_back("GATEWAY_INTERFACE=CGI/1.1");
        env_vars.push_back("REDIRECT_STATUS=200");
        env_vars.push_back("SERVER_NAME=" + std::string(config.server_name.empty() ? "localhost" : config.server_name));
        std::ostringstream port_str;
        port_str << server_port;
        env_vars.push_back("SERVER_PORT=" + port_str.str());
        env_vars.push_back("HTTP_HOST=" + request.getHeader("Host"));
        env_vars.push_back("DOCUMENT_ROOT=" + std::string(config.root.empty() ? "www" : config.root));
        env_vars.push_back("PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin");
        if (!request.getQuery().empty()) {
            env_vars.push_back("QUERY_STRING=" + request.getQuery());
        }
        if (!request.getBody().empty()) {
            std::ostringstream cl;
            cl << request.getBody().length();
            env_vars.push_back("CONTENT_LENGTH=" + cl.str());
            env_vars.push_back("CONTENT_TYPE=" + request.getHeader("Content-Type"));
        }
        std::string visit_count = getenv("VISIT_COUNT") ? std::string(getenv("VISIT_COUNT")) : "0";
        env_vars.push_back("VISIT_COUNT=" + visit_count);

        // Convertir variables de entorno a char*
        std::vector<char*> envp;
        for (size_t i = 0; i < env_vars.size(); ++i) {
            envp.push_back(const_cast<char*>(env_vars[i].c_str()));
            std::cerr << "DEBUG: CGI Env[" << i << "]: " << env_vars[i] << std::endl;
        }
        envp.push_back(NULL);

        // Ejecutar el intérprete CGI con la ruta completa del script
        std::cerr << "DEBUG: About to call execve with interpreter: " << cgi_interpreter << ", script: " << script_path << std::endl;
        const char* argv[] = {cgi_interpreter.c_str(), script_path.c_str(), NULL};
        execve(cgi_interpreter.c_str(), (char* const*)argv, envp.data());
        std::cerr << "ERROR: execve failed for interpreter: " << cgi_interpreter 
                  << ", script: " << script_path << ", errno: " << errno 
                  << " (" << strerror(errno) << ")" << std::endl;
        _exit(1);
    }

    // Proceso padre
    close(pipefd_out[1]);
    close(pipefd_err[1]);
    close(pipefd_in[0]);

    // Enviar el cuerpo de la solicitud al script CGI
    if (!request.getBody().empty()) {
        std::cerr << "DEBUG: Body to CGI stdin (string): [" << request.getBody() << "]" << std::endl << std::flush;
        std::cerr << "DEBUG: Body to CGI stdin (hex): ";
        for (size_t i = 0; i < request.getBody().size(); ++i) {
            std::cerr << std::hex << std::setw(2) << std::setfill('0') << (int)(unsigned char)request.getBody()[i] << " ";
        }
        std::cerr << std::dec << std::endl << std::flush;
        ssize_t bytes_written = write(pipefd_in[1], request.getBody().c_str(), request.getBody().length());
        if (bytes_written != static_cast<ssize_t>(request.getBody().length())) {
            std::cerr << "ERROR: Failed to write body to CGI stdin, bytes_written: " << bytes_written 
                      << ", expected: " << request.getBody().length() 
                      << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl;
        } else {
            std::cerr << "DEBUG: Wrote body to CGI stdin, length: " << request.getBody().length() << std::endl;
        }
    }
    close(pipefd_in[1]);

    // Leer la salida de stderr del script CGI
    std::string err_output;
    char err_buffer[4096] = {0};
    ssize_t bytes_read;
    while ((bytes_read = read(pipefd_err[0], err_buffer, sizeof(err_buffer) - 1)) > 0) {
        err_buffer[bytes_read] = '\0';
        err_output += err_buffer;
        std::cerr << "DEBUG: Read " << bytes_read << " bytes from CGI stderr: " << err_buffer << std::endl;
    }
    close(pipefd_err[0]);
    if (!err_output.empty()) {
        std::cerr << "ERROR: CGI stderr output: " << err_output << std::endl;
    }

    // Leer la salida de stdout del script CGI
    std::string output;
    char buffer[4096] = {0};
    while ((bytes_read = read(pipefd_out[0], buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        output += buffer;
        std::cerr << "DEBUG: Read " << bytes_read << " bytes from CGI stdout" << std::endl;
    }
    close(pipefd_out[0]);

    // Esperar a que el proceso hijo termine con timeout
    int status;
    pid_t result = waitpid(pid, &status, WNOHANG);  // Non-blocking wait
    if (result == 0) {
        // Process still running, give it a moment
        usleep(100000);  // Wait 100ms
        result = waitpid(pid, &status, WNOHANG);
        if (result == 0) {
            // Still running, kill it to prevent hanging
            std::cerr << "WARNING: CGI process timeout, killing process " << pid << std::endl;
            kill(pid, SIGTERM);
            usleep(50000);  // Give it 50ms to terminate gracefully
            kill(pid, SIGKILL);  // Force kill if still alive
            waitpid(pid, &status, 0);  // Clean up zombie
        }
    }
    
    if (result > 0 && WIFEXITED(status) && WEXITSTATUS(status) == 0) {
        std::cerr << "DEBUG: CGI executed successfully, raw output length: " << output.length() << std::endl;
        
        // Procesar la salida para separar headers CGI del contenido
        std::string cgi_headers;
        std::string cgi_body;

        size_t header_end = output.find("\r\n\r\n");
        if (header_end != std::string::npos) {
            cgi_headers = output.substr(0, header_end);
            cgi_body = output.substr(header_end + 4);
        } else {
            header_end = output.find("\n\n");
            if (header_end != std::string::npos) {
                cgi_headers = output.substr(0, header_end);
                cgi_body = output.substr(header_end + 2);
            } else {
                // No hay headers separados, todo es contenido
                cgi_body = output;
            }
        }

        std::cerr << "DEBUG: CGI headers: [" << cgi_headers << "]" << std::endl;
        std::cerr << "DEBUG: CGI body: [" << cgi_body << "]" << std::endl;
        std::cerr << "DEBUG: CGI body output length: " << cgi_body.length() << std::endl;
        
        return std::make_pair(cgi_body, 200);
    } else {
        std::cerr << "ERROR: CGI execution failed, status: " << status 
                  << ", WEXITSTATUS: " << WEXITSTATUS(status) 
                  << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl;
        if (!err_output.empty()) {
            return std::make_pair("<html><body><h1>500 Internal Server Error - CGI Execution Failed: " + err_output + "</h1></body></html>", 500);
        }
        return std::make_pair("<html><body><h1>500 Internal Server Error - CGI Execution Failed</h1></body></html>", 500);
    }
}