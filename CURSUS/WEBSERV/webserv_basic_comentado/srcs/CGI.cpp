#include "CGI.hpp"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <limits.h>

/* Requiere ejecutarse en dos procesos porque el script se debe ejecutar como un programa independiente 
mientras que el servidor sigue en ejecucicón además de que necesitára interactuar con él al mismo tiempo.
De esa forma el script no interfiere en que el servidor siga manejando nuevas solicitudes
*/
CGI::CGI(const Request& req, const LocationConfig& loc)
    : request(req), location(loc) 
{
    std::cerr << "DEBUG: CGI constructor called for URI: " << req.getUri() << ", cgi_path: " << loc.cgi_path << std::endl;
    std::cerr.flush();
}


/* Este método ejecuta el script solicitado por el cliente dentro de un proceso hijo mientras
el servidor sigue activo y recibiendo solicitudes (en el proceso padre), y una vez terminado, 
devuelve al proceso padre el resultado para poder devolverlo al cliente */
std::string CGI::execute() 
{
    int pipe_in[2], pipe_out[2];
    pid_t pid;
    std::string output;

    // Si la creación de pipes da error
    if (pipe(pipe_in) == -1 || pipe(pipe_out) == -1) 
    {
        std::cerr << "DEBUG: Failed to create pipes: " << strerror(errno) << std::endl;
        std::cerr.flush();
        return "";
    }

    pid = fork();
    // Si el fork da error
    if (pid == -1) 
    {
        std::cerr << "DEBUG: Failed to fork: " << strerror(errno) << std::endl;
        std::cerr.flush();
        close(pipe_in[0]); close(pipe_in[1]);
        close(pipe_out[0]); close(pipe_out[1]);
        return "";
    }

    if (pid == 0) //Proceso hijo 
    { 
        // ============================ CONFIGURACIÓN DE PIPES ==================================

        close(pipe_in[1]);
        close(pipe_out[0]);

        // Redirección de la entrada estandar al pipe del proceso padre
            // hasta que el proceso hijo no recibe los datos x este pipe del proceso padre no empieza
        dup2(pipe_in[0], STDIN_FILENO);
        dup2(pipe_out[1], STDOUT_FILENO);
        close(pipe_in[0]);
        close(pipe_out[1]);

        // ============================ ======================= ==================================

        /* ==================== CREACIÓN DE LA RUTA DEL NOMBRE DE ARCHIVO =========================

        - OBTIENE LA RUTA COMPLETA DEL SCRIPT
            petición -> GET /cgi-bin/hello.php?name=Juan HTTP/1.1
            devuelve -> "/cgi-bin/hello.php?name=Juan" */
        std::string script_path = request.getUri();

        // BUSCA LA POS DE LA ULTIMA APARICION DE "/"
        size_t pos = script_path.find_last_of('/');
        
        // SI ENCONTRO "/" 
            // EXTRAE EL NOMBRE DEL ARCHIVO (a partir de la /)
            // ej: hello.php?name=Juan
        if (pos != std::string::npos)
            script_path = script_path.substr(pos + 1);
        
        // CONSTRUYE LA RUTA COMPLETA DEL SCRIPT
            // combina location.root (/var/www/cgi_bin) con la ruta del script (hello.php?name....)
            // ruta completa -> /var/www/cgi-bin/hello.php?name=Juan
        std::string full_path = location.root + "/" + script_path;

        // ============================ ======================= ==================================

        // ====================  CONFIGURACIÓN DE ENV PARA EJEC. DE CGI =========================

        char abs_path[PATH_MAX];

        // COMPRUEBA SI LA RUTA ES VÁLIDA (si el archivo existe)
            // realpath asigna a abs_path (ruta absoluta) -> /var/www/cgi-bin/hello.php (sin name=Juan)
        if (realpath(full_path.c_str(), abs_path) == NULL) 
        {
            std::cerr << "DEBUG: Failed to resolve script path: " << full_path << " (errno: " << strerror(errno) << ")" << std::endl;
            std::cerr.flush();
            exit(1);
        }

        std::cerr << "DEBUG: Executing CGI with script: " << abs_path << ", cgi_path: " << location.cgi_path << std::endl;
        std::cerr.flush();

        // Declaración de vector para almacenar las var de entorno necesarias para ejecutar el script
        std::vector<char*> env;
        std::ostringstream oss; // para constuir cada variable -> clave = valor

        // CONFIGURACIÓN DE VARIABLES DE ENTORNO PARA EL EXECVE (execute with environment)
            // Ejemplo: "SCRIPT_FILENAME=/var/www/cgi-bin/hello.php".
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
        
        
        // CONFIGURACIÓN DE ARGUMENTOS PARA EXCEVE
            // array de punteros a cadenas para contener 
            //los argumentos necesarios para ejecutar el script:
            /*  EJEMPLO:
                    location.cgi_path = "/usr/bin/php" (ruta (del SO) para seleccionar el programa que ejecutará el script)
                        // bin -> donde suelen estar los ejecutables de los programas
                        // php -> antes, se debe haber descargado PHP en el servidor (apt-get install php)
                    abs_path = "/var/www/cgi-bin/hello.php" (script a ejecutar)

                    array:
                        args[0] = "/usr/bin/php";   // ruta del programa php
                        args[1] = "/var/www/cgi-bin/hello.php";   // ruta del Script CGI
                        args[2] = NULL;   // Fin del array */
        char* args[] = {(char*)location.cgi_path.c_str(), abs_path, NULL};

        // Ejecuta el programa (args[0])
        // Pasa los argumentos (arg) al programa (en este caso args[1])
        // Usa las var de entorno definidas (env.data)
            // la salida será capturada por el proceso padre
            // (ya que se modificaron las salidas estandar a los pipes)
    // ============================ ======================= ==================================
        // EJECUCIÓN DEL SCRIPT
        execve(args[0], args, env.data());

        std::cerr << "DEBUG: Failed to execute CGI: " << strerror(errno) << std::endl;
        std::cerr.flush();
        exit(1);
        // LO que devuelva EXECVE lo recibe el proceso padre
    } 
    else { // Proceso padre
        close(pipe_in[0]);
        close(pipe_out[1]);

        // Escribe en el pipe in[1] los 17 bytes de la solicitud del cliente 
            // !!!! el hijo tiene que esperar a recibir los datos del padre x ese pipe!!!
            // request.getBody() devuelve "name=Juan&age=30".
            // request.getBody().c_str() convierte esto en un puntero a "name=Juan&age=30".
            // request.getBody().length() devuelve 17 (número de caracteres).
        write(pipe_in[1], request.getBody().c_str(), request.getBody().length());
        close(pipe_in[1]);

        char buffer[1024];
        ssize_t bytes;

        // Lee la salida generada por el proceso hijo (que es quien ejecuta el script)
            // va leyendo mientras y hasta q el hijo va enviando datos 
            // (no necesita esperar a q acabe de enviarlos todos)
        while ((bytes = read(pipe_out[0], buffer, sizeof(buffer) - 1)) > 0) 
        {
            buffer[bytes] = '\0'; // pone el /0 al final de la cadena
            output += buffer; // va guardando lo que va leyendo
        }
        close(pipe_out[0]);

        int status;

        // DETIENE EL AVANZE DEL PROCESO DEL PADRE HASTA QUE EL HIJO TERMINE
            // controla si el proceso hijo tuvo errores (status)
        waitpid(pid, &status, 0); 
        
        // verifica si el proceso hijo devolvió algún error
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) 
        {
            std::cerr << "DEBUG: CGI process exited with status: " << WEXITSTATUS(status) << std::endl;
            std::cerr.flush();
            return "";
        }
    }

    std::cerr << "DEBUG: CGI output length: " << output.length() << std::endl;
    std::cerr.flush();
    return output;
}