#include "Response.hpp"
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <iostream>
#include <cstdlib>
#include <string.h>

/*
Este archivo implementa toda la lógica para analizar la petición HTTP, 
decidir la respuesta adecuada (archivo, CGI, error, etc.), 
construir la respuesta HTTP y devolverla al cliente, 
gestionando correctamente los distintos métodos y posibles errores.

---

### 1. **Construcción de la respuesta HTTP**
- La clase `Response` se encarga de crear la respuesta HTTP que el servidor enviará al cliente,
 usando la petición recibida (`Request`) y la configuración del servidor (`ServerConfig`).

### 2. **Procesamiento de la petición**
- El método `handleRequest()` decide cómo responder según la petición:
  - Busca la configuración (`LocationConfig`) adecuada para la URI solicitada.
  - Si no encuentra una ubicación válida, responde con un **404 Not Found**.
  - Si hay una redirección configurada, responde con un **301 Moved Permanently**.
  - Según el método HTTP (`GET`, `POST`, `DELETE`), llama al manejador correspondiente:
    - **GET**: Lee y devuelve archivos.
    - **POST**: Guarda archivos subidos.
    - **DELETE**: Borra archivos.
    - Si hay CGI configurado, ejecuta el CGI.
    - Si el método no está permitido, responde con **405 Method Not Allowed**.

### 3. **Manejo de archivos**
- Usa funciones del sistema para comprobar si los archivos existen, leerlos, 
escribirlos o borrarlos según el método HTTP.

### 4. **Cabeceras y cuerpo de la respuesta**
- Añade cabeceras como `Content-Type`, `Content-Length` y `Connection` según la petición 
y el resultado.
- El cuerpo de la respuesta puede ser el contenido de un archivo, un mensaje de error, 
o la salida de un CGI.

### 5. **Generación de la respuesta final**
- El método `generate()` construye la respuesta HTTP completa (cabeceras + cuerpo) 
en formato texto listo para enviar al cliente.

### 6. **Soporte para CGI**
- Si la petición requiere ejecutar un CGI, lo hace y usa la salida como cuerpo de la respuesta.

### 7. **Gestión de errores**
- Devuelve mensajes y códigos de error apropiados (404, 403, 405, 500, etc.) según el caso.

### 8. **Depuración**
- Imprime mensajes de depuración en consola para seguir el flujo de ejecución y detectar problemas.

---

*/
Response::Response(const Request& req, const ServerConfig& conf)
    : status_code(200), status_message("OK"), request(req), server_config(conf) 
{   // 200 (petición exitosa), 
    // inicializa el atributo request con req(request)-> la petición
    // 
    std::cerr << "DEBUG: Response constructor called for method: " << req.getMethod() << ", URI: " << req.getUri() << std::endl;
    std::cerr.flush();
}

/* Esta línea busca la configuración de ubicación más adecuada para la URI solicitada 
por el cliente.  

Primero, obtiene la URI de la petición HTTP usando `request.getUri()`. 
Luego, llama al método `findLocation`, que recorre todas las ubicaciones (`LocationConfig`) 
definidas en la configuración del servidor y selecciona la que mejor coincide con esa URI.  
El resultado es un puntero a la configuración de ubicación encontrada, que se usará 
para decidir cómo responder a la petición (por ejemplo, qué archivo servir, 
si hay que redirigir, si se permite el método, etc.).

En resumen, esta línea determina qué reglas y recursos del servidor se aplican a la 
petición del cliente según la ruta solicitada.*/

void Response::handleRequest() 
{
    // URI -> Uniform Resource Identifier
    // localiza le (index.html dentro de ....localhost:8080/....)
    // busca la mejor coincidencia encontrada con la ruta solicitada
    const LocationConfig* location = findLocation(request.getUri());

    std::cerr << "DEBUG: Handling request for URI: " << request.getUri() << std::endl;
    std::cerr.flush();

    if (!location) // si no encuentra ninguna coincidencia
    {
        status_code = 404;
        status_message = "Not Found";


        setBody("<h1>404 Not Found</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        
        
        std::cerr << "DEBUG: No location found, returning 404" << std::endl;
        std::cerr.flush();
        return;
    }

    if (!location->redirect.empty()) // si contiene una redirección
    {
        status_code = 301;
        status_message = "Moved Permanently";
        
        setHeader("Location", location->redirect);
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        return;
    }

    // solo hay GET (con o sin cgi), POST (con o sin cgi) y DELETE

    // GET + ruta del CGI(/usr/bin/php) el cliente solicita ejecutar un script
        // GET -> para pedir datos al servidor
    if (request.getMethod() == "GET" && !location->cgi_path.empty()) 
        handleCgiRequest(*location);
    // POST con ruta del GCI -> Ejecutar un script con los datos enviados
        // POST -> para enviar datos al servidor
    else if (request.getMethod() == "POST" && !location->cgi_path.empty())
        handleCgiRequest(*location);
    // GET sin ruta CGI -> solicita archivo estático (html, css, etc)
    else if (request.getMethod() == "GET")
        handleGetRequest(*location);
    // POST sin ruta CGI -> guarda archivo o datos enviados x el cliente
    else if (request.getMethod() == "POST")
        handlePostRequest(*location);
    // Elimina un archivo del servidor
    else if (request.getMethod() == "DELETE")
        handleDeleteRequest(*location);
    // Método no encontrado
    else {
        status_code = 405;
        status_message = "Method Not Allowed";
        setBody("<h1>405 Method Not Allowed</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        std::cerr << "DEBUG: Method not supported: " << request.getMethod() << std::endl;
        std::cerr.flush();
    }
}

void Response::handleGetRequest(const LocationConfig& location) 
{
    // Construye la ruta completa del archivo solicitado por el cliente
    // (he cambiado el formato de este if else...)
    std::string path;
    if (request.getUri() == "/") // si solicita la raiz
        path = cleanPath(location.root + "/" + location.index);
    else // sino, se elimina la parte de la uri que coincide con la ruta ya configurada...
        path = cleanPath(location.root + "/" + request.getUri().substr(location.path.length()));
    std::cerr << "DEBUG: Handling GET request for path: " << path << std::endl;
    std::cerr.flush();

    struct stat st;
    // Compruba si el archivo existe y q no sea un directorio
    if (stat(path.c_str(), &st) != 0 || !S_ISREG(st.st_mode)) 
    {
        status_code = 404;
        status_message = "Not Found";
        setBody("<h1>404 Not Found</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        std::cerr << "DEBUG: File not found or not a regular file: " << path << std::endl;
        std::cerr.flush();
        return;
    }

    std::ifstream file(path.c_str());

    // si no se puede abrir
    if (!file.is_open()) 
    {
        status_code = 403;
        status_message = "Forbidden";
        setBody("<h1>403 Forbidden</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        std::cerr << "DEBUG: Unable to open file: " << path << std::endl;
        std::cerr.flush();
        return;
    }

    // Vuelca en buffer todo el contenido del archivo solicitado
    std::stringstream buffer;
    buffer << file.rdbuf();

    // muestra el contenido
    setBody(buffer.str());
    setHeader("Content-Type", getContentType(path));
    setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
    std::cerr << "DEBUG: File served successfully: " << path << std::endl;
    std::cerr.flush();
}

void Response::handlePostRequest(const LocationConfig& location) 
{
    std::cerr << "DEBUG: Handling POST request with upload_path: " << location.upload_path << std::endl;
    std::cerr.flush();

    // Comprueba que esté definido un directorio para subir archivos antes de
    // procesar la petición
    if (location.upload_path.empty()) 
    {
        status_code = 403;
        status_message = "Forbidden";
        setBody("<h1>403 Forbidden</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        std::cerr << "DEBUG: No upload_path specified" << std::endl;
        std::cerr.flush();
        return;
    }

    // Extrae el nombre del archivo q el cliente desea subir o procesar
    std::string filename = request.getUri().substr(request.getUri().find_last_of('/') + 1);
    
    // Si el nombre del archivo termina en  / o está vacío
    if (filename.empty()) 
    {
        status_code = 400;
        status_message = "Bad Request";
        setBody("<h1>400 Bad Request</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        std::cerr << "DEBUG: No filename provided" << std::endl;
        std::cerr.flush();
        return;
    }

    // Construye la ruta completa donde el cliente quiere guardar el archivo
    std::string path = cleanPath(location.upload_path + "/" + filename);
    std::cerr << "DEBUG: Uploading file to: " << path << std::endl;
    std::cerr.flush();

    // convierte la ruta a ofstream
    std::ofstream file(path.c_str());

    // Sino la puede abrir
    if (!file.is_open()) 
    {
        status_code = 403;
        status_message = "Forbidden";
        setBody("<h1>403 Forbidden</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        std::cerr << "DEBUG: Unable to open file for writing: " << path << std::endl;
        std::cerr.flush();
        return;
    }

    // Escribe el contenido del cuerpo de la solicitud HTTP en el archivo
    file << request.getBody();

    // Cuando acaba de escribir en el archivo lo cierra
    file.close();

    status_code = 201;
    status_message = "Created";
    setBody("<h1>201 Created</h1>");
    setHeader("Content-Type", "text/html");
    setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
    std::cerr << "DEBUG: File uploaded successfully: " << path << std::endl;
    std::cerr.flush();
}

void Response::handleDeleteRequest(const LocationConfig& location) 
{
    // Construye la ruta completa del archivo que desea eliminar del servidor
    std::string path = cleanPath(location.root + "/" + request.getUri().substr(location.path.length()));
    std::cerr << "DEBUG: Handling DELETE request for path: " << path << std::endl;
    std::cerr.flush();

    // Verifica si el archivo existe y si es regular (no un directorio)
    struct stat st;
    if (stat(path.c_str(), &st) != 0 || !S_ISREG(st.st_mode)) 
    {
        status_code = 404;
        status_message = "Not Found";
        setBody("<h1>404 Not Found</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        std::cerr << "DEBUG: File not found or not a regular file: " << path << std::endl;
        std::cerr.flush();
        return;
    }

    // Comprueba si la eliminación del archivo falló
    if (unlink(path.c_str()) != 0)
    {
        status_code = 403;
        status_message = "Forbidden";
        setBody("<h1>403 Forbidden</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        std::cerr << "DEBUG: Unable to delete file: " << path << std::endl;
        std::cerr.flush();
        return;
    }

    status_code = 200;
    status_message = "OK";
    setBody("<h1>200 OK: File Deleted</h1>");
    setHeader("Content-Type", "text/html");
    setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
    std::cerr << "DEBUG: File deleted successfully: " << path << std::endl;
    std::cerr.flush();
}

void Response::handleCgiRequest(const LocationConfig& location) 
{
    if (!location.methods.empty())  // vuelve a comprobar q haya metodo..
    {
        bool method_allowed = false;
        std::cerr << "DEBUG: Checking allowed methods for " << request.getMethod() << std::endl;
        std::cerr.flush();

        // Recorre todos los métodos definidos para check si está permitido
        for (size_t i = 0; i < location.methods.size(); ++i) 
        {
            std::string method = cleanMethod(location.methods[i]);
            std::cerr << "DEBUG: Method " << method << std::endl;
            std::cerr.flush();

            // si coincide con un método permitido
            if (method == request.getMethod()) 
            {
                method_allowed = true;
                break;
            }
        }

        // Si no está permitido
        if (!method_allowed) 
        {
            status_code = 405;
            status_message = "Method Not Allowed";
            setBody("<h1>405 Method Not Allowed</h1>");
            setHeader("Content-Type", "text/html");
            setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
            std::cerr << "DEBUG: Method not allowed: " << request.getMethod() << std::endl;
            std::cerr.flush();
            return;
        }
    }

    std::cerr << "DEBUG: Executing CGI with cgi_path: " << cleanPath(location.cgi_path) << std::endl;
    std::cerr.flush();

    // como el cliente solicitó GET + cgi (ruta)
        // creo objeto cgi
    CGI cgi(request, location);

    // Ejecuta el script CGI y devuelve su salida
    std::string output = cgi.execute();
    
    // Si no devuelve nada
    if (output.empty())
    {
        std::cerr << "DEBUG: CGI output is empty" << std::endl;
        std::cerr.flush();
        status_code = 500;
        status_message = "Internal Server Error";
        setBody("<h1>500 Internal Server Error</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        return;
    }

    // Imprime la salida del script CGI
    setBody(output);
    setHeader("Content-Type", "text/html");
    setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
    std::cerr << "DEBUG: CGI executed successfully" << std::endl;
    std::cerr.flush();
}



const LocationConfig* Response::findLocation(const std::string& uri) const 
{
    const std::vector<LocationConfig>& locations = server_config.locations;
    const LocationConfig* best_match = NULL;
    size_t longest_match = 0;

    // NORMALIZA LA URI (elimina el "/")
    std::string normalized_uri = uri;
    if (!normalized_uri.empty() && normalized_uri[0] == '/')
        normalized_uri = normalized_uri.substr(1);

    std::cerr << "DEBUG: Finding location for URI: " << uri << ", normalized: " << normalized_uri << std::endl;
    std::cerr.flush();


    for (size_t i = 0; i < locations.size(); ++i) 
    {
        std::string path = cleanPath(locations[i].path);
        if (path[0] == '/') // si la ruta empieza por "/" la borra
            path = path.substr(1);

        // Imprime la ruta y todos los metodos...
        std::cerr << "DEBUG: Checking location path: " << path << " (original: " << locations[i].path << "), methods: ";
        for (size_t j = 0; j < locations[i].methods.size(); ++j)
            std::cerr << locations[i].methods[j] << " ";
        std::cerr << ", root: " << locations[i].root << ", upload_path: " << locations[i].upload_path << ", cgi_path: " << locations[i].cgi_path << std::endl;
        std::cerr.flush();

        // Comprueba si la ruta contiene algo y la pos. de la ruta dentro de la URI
        if (path.empty() || normalized_uri.find(path) == 0) 
        {
            // Comprueba:
            //  - si la long de la URI normalizada es = a la de la ruta
            //  - si justo después de la ruta hay "/"
            //  - si termina con \0
            if (normalized_uri.length() == path.length() || 
                normalized_uri[path.length()] == '/' || 
                normalized_uri[path.length()] == '\0') 
                {
                // busca la coincidencia más exacta con la ruta
                if (path.length() >= longest_match) 
                {
                    longest_match = path.length();
                    best_match = &locations[i]; // guarda la mejor coincidencia

                    std::cerr << "DEBUG: New best match: " << locations[i].path << std::endl;
                    std::cerr.flush();
                }
            }
        }
    }
    
    if (best_match)  // si encuentra una coincidencia la imprime
    {
        std::cerr << "DEBUG: Selected location: " << best_match->path << ", root: " << cleanPath(best_match->root) << ", index: " << cleanPath(best_match->index) << std::endl;
        std::cerr.flush();
    } else {
        std::cerr << "DEBUG: No location found for URI: " << uri << "\n";
        std::cerr.flush();
    }
    return best_match; // devuelve la mejor coincidencia encontrada
}


/* simplemente elimina las barras que sobran si hay más de 1 */
std::string Response::cleanPath(const std::string& path) const 
{
    std::string result = path;
    while (result.find("//") != std::string::npos)
        result.replace(result.find("//"), 2, "/");

    if (!result.empty() && result[result.length() - 1] == '/')
        result = result.substr(0, result.length() - 1);
    return result;
}

/*elimina los \t\n\r o espacios */
std::string Response::cleanMethod(const std::string& method) const 
{
    std::string result = method;
    size_t pos = result.find_first_of(" \t\n\r");
    if (pos != std::string::npos)
        result = result.substr(0, pos);
    return result;
}



void Response::setHeader(const std::string& key, const std::string& value) 
{
    headers[key] = value;
}

void Response::setBody(const std::string& b) 
{
    body = b;
    std::ostringstream oss;
    oss << body.length();
    setHeader("Content-Length", oss.str());
}


/* Ensambla en una sola cadena todo el mensaje HTTP que se enviará al cliente*/
std::string Response::generate() 
{
    std::ostringstream response; // ouput string stream ( para escribir datos)

    // Guarda en response el protocolo, el codigo de estado (200) y el mensaje de estado (OK)
    response << "HTTP/1.1 " << status_code << " " << status_message << "\r\n";

    // Añade las cabeceras configuradas anteriormente
    for (std::map<std::string, std::string>::const_iterator it = headers.begin(); it != headers.end(); ++it)
        response << it->first << ": " << it->second << "\r\n";
    response << "\r\n" << body; // <h1>Hello, juan<h1>

    std::cerr << "DEBUG: Generated response: " << response.str() << std::endl;
    std::cerr.flush();
    return response.str();
}

std::string Response::getContentType(const std::string& path) 
{
    // rfind devuelve un índice a la posición donde encuentra .html
    // Comprueba que es posición no sea el final de la cadena (no se ha encontrado)
    if (path.rfind(".html") != std::string::npos) 
        return "text/html";
    if (path.rfind(".css") != std::string::npos) 
        return "text/css";
    if (path.rfind(".js") != std::string::npos) 
        return "application/javascript";
    if (path.rfind(".jpg") != std::string::npos || path.rfind(".jpeg") != std::string::npos) 
        return "image/jpeg";
    if (path.rfind(".png") != std::string::npos) 
        return "image/png";
    if (path.rfind(".php") != std::string::npos) 
        return "text/html";
    return "text/plain";
}