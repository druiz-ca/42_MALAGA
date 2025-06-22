#include "CGI.hpp"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <limits.h>

CGI::CGI(const Request& req, const LocationConfig& loc)
    : request(req), location(loc) {
    std::cerr << "DEBUG: CGI constructor called for URI: " << req.getUri() << ", cgi_path: " << loc.cgi_path << std::endl;
    std::cerr.flush();
}

std::string CGI::execute() {
    int pipe_in[2], pipe_out[2];
    pid_t pid;
    std::string output;

    if (pipe(pipe_in) == -1 || pipe(pipe_out) == -1) {
        std::cerr << "DEBUG: Failed to create pipes: " << strerror(errno) << std::endl;
        std::cerr.flush();
        return "";
    }

    pid = fork();
    if (pid == -1) {
        std::cerr << "DEBUG: Failed to fork: " << strerror(errno) << std::endl;
        std::cerr.flush();
        close(pipe_in[0]); close(pipe_in[1]);
        close(pipe_out[0]); close(pipe_out[1]);
        return "";
    }

    if (pid == 0) { // Child process
        close(pipe_in[1]);
        close(pipe_out[0]);

        dup2(pipe_in[0], STDIN_FILENO);
        dup2(pipe_out[1], STDOUT_FILENO);
        close(pipe_in[0]);
        close(pipe_out[1]);

        std::string script_path = request.getUri();
        size_t pos = script_path.find_last_of('/');
        if (pos != std::string::npos) {
            script_path = script_path.substr(pos + 1);
        }
        std::string full_path = location.root + "/" + script_path;
        char abs_path[PATH_MAX];
        if (realpath(full_path.c_str(), abs_path) == NULL) {
            std::cerr << "DEBUG: Failed to resolve script path: " << full_path << " (errno: " << strerror(errno) << ")" << std::endl;
            std::cerr.flush();
            exit(1);
        }

        std::cerr << "DEBUG: Executing CGI with script: " << abs_path << ", cgi_path: " << location.cgi_path << std::endl;
        std::cerr.flush();

        std::vector<char*> env;
        std::ostringstream oss;
        oss << "SCRIPT_FILENAME=" << abs_path;
        env.push_back(strdup(oss.str().c_str()));
        oss.str("");
        oss << "REQUEST_METHOD=" << request.getMethod();
        env.push_back(strdup(oss.str().c_str()));
        oss.str("");
        oss << "CONTENT_LENGTH=" << request.getHeader("Content-Length");
        env.push_back(strdup(oss.str().c_str()));
        oss.str("");
        oss << "CONTENT_TYPE=" << request.getHeader("Content-Type");
        env.push_back(strdup(oss.str().c_str()));
        oss.str("");
        oss << "QUERY_STRING=" << request.getQuery();
        env.push_back(strdup(oss.str().c_str()));
        oss.str("");
        oss << "GATEWAY_INTERFACE=CGI/1.1";
        env.push_back(strdup(oss.str().c_str()));
        oss.str("");
        oss << "DOCUMENT_ROOT=" << location.root;
        env.push_back(strdup(oss.str().c_str()));
        oss.str("");
        oss << "SERVER_PROTOCOL=HTTP/1.1";
        env.push_back(strdup(oss.str().c_str()));
        oss.str("");
        oss << "SERVER_PORT=8080";
        env.push_back(strdup(oss.str().c_str()));
        oss.str("");
        oss << "REDIRECT_STATUS=200";
        env.push_back(strdup(oss.str().c_str()));
        env.push_back(NULL);

        char* args[] = {(char*)location.cgi_path.c_str(), abs_path, NULL};
        execve(args[0], args, env.data());
        std::cerr << "DEBUG: Failed to execute CGI: " << strerror(errno) << std::endl;
        std::cerr.flush();
        exit(1);
    } else { // Parent process
        close(pipe_in[0]);
        close(pipe_out[1]);

        write(pipe_in[1], request.getBody().c_str(), request.getBody().length());
        close(pipe_in[1]);

        char buffer[1024];
        ssize_t bytes;
        while ((bytes = read(pipe_out[0], buffer, sizeof(buffer) - 1)) > 0) {
            buffer[bytes] = '\0';
            output += buffer;
        }
        close(pipe_out[0]);

        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            std::cerr << "DEBUG: CGI process exited with status: " << WEXITSTATUS(status) << std::endl;
            std::cerr.flush();
            return "";
        }
    }

    std::cerr << "DEBUG: CGI output length: " << output.length() << std::endl;
    std::cerr.flush();
    return output;
}