#include "Request.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>


/*
curl:
Es una herramienta de línea de comandos que permite realizar solicitudes HTTP y otros protocolos.
*/
Request::Request() 
{
    std::cerr << "DEBUG: Default Request constructor called\n";
    std::cerr.flush();
}

Request::Request(const std::string& raw_request) 
{
    std::cerr << "DEBUG: Raw request constructor called\n";
    parseRequest(raw_request);
}


/* Método que extrae los datos relevantes de la solicitud HTTP y los
almacena en los atributos de la propia clase Request*/
bool Request::parse(std::string& buffer) 
{
    // ====== EXTRAE DE LAS CABECERAS LA URI Y LA QUERY Y EL RESTO LO GUARDA EN HEADERS ===== /
    std::cerr << "DEBUG: Parsing buffer: " << buffer << "\n";
    std::cerr.flush();

    // Busca la pos donde empieza \r\n\r....(el delimitador) EJ:
        // POST /cgi-bin/hello.php HTTP/1.1\r\n
        //Host: localhost\r\n
        //Content-Type: application/x-www-form-urlencoded\r\n
        //Content-Length: 17\r\n
        //Connection: keep-alive\r\n
        //\r\n <----
        //name=Juan&age=30 --> el body de la solicitud
    size_t header_end = buffer.find("\r\n\r\n");
    
    // Sino la encuentra
    if (header_end == std::string::npos) 
    {
        std::cerr << "DEBUG: Incomplete request, missing \\r\\n\\r\\n\n";
        std::cerr.flush();
        return false;
    }

    // Extrae la cabecera 
        // (todo el contenido hasta los \r\n...(el delimitador))
    std::string header = buffer.substr(0, header_end);

    // lo convierte a istringstream
        // para detectar cada \n como nueva linea para el getline!!
    std::istringstream iss(header);
    std::string line;
    bool first_line = true;

    // Recorre las cabeceras linea a linea
    while (std::getline(iss, line)) 
    {
        // salta lineas vacias o solo con \r salta a la sig. linea
        if (line.empty() || line == "\r") 
            continue;
        
        // Borra todos los "\r" de la linea
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());

        // solo para la primera linea de las cabeceras
        if (first_line) 
        {
            std::istringstream line_ss(line); // convierte la linea a istringstream

            // desglosa la linea (separando por espacios)
            line_ss >> method >> uri >> protocol;

            // Comprueba que todos los campos contenga información
            if (method.empty() || uri.empty() || protocol.empty()) 
            {
                std::cerr << "DEBUG: Invalid request line: " << line << "\n";
                std::cerr.flush();
                return false;
            }
            
            // Busca la pos de ? en la URI ej:
                // uri = "/cgi-bin/hello.php?name=Juan&age=30";
                    // URI -> ruta + consulta (separada por ?)
                //query_pos = 16; // posición del carácter '?'
            size_t query_pos = uri.find('?');

            // Si la encuentra lo divide entre la query y la uri
            if (query_pos != std::string::npos) 
            {
                query = uri.substr(query_pos + 1);
                uri = uri.substr(0, query_pos);
                /*ej:   query = "name=Juan&age=30"; // parámetros enviados por el cliente
                        uri = "/cgi-bin/hello.php"; // ruta del recurso solicitado*/
            }
            std::cerr << "DEBUG: Parsed method: " << method << ", uri: " << uri << ", query: " << query << ", protocol: " << protocol << "\n";
            std::cerr.flush();
            first_line = false; // establece en false para no volver a entrar aquí
        }
        else // el resto de lineas
        {
            // busca la pos de ":" (colon)
            size_t colon = line.find(": ");

            // Si la encuentra 
            if (colon != std::string::npos) 
            {
                // separa la clave y el valor de las cabeceras ,ej:
                    /* headers = {
                    "Host": "localhost",
                    "Content-Type": "application/x-www-form-urlencoded",
                    "Content-Length": "17",
                    "Connection": "keep-alive" };*/
                std::string key = line.substr(0, colon);
                std::string value = line.substr(colon + 2);
                headers[key] = value;

                std::cerr << "DEBUG: Header " << key << ": " << value << "\n";
                std::cerr.flush();
            }
        }
    }

    // =======================================================================================/


    // Extre la longitud del contenido si existe
        // el navegador es el q calcula la longitud de la request
    size_t content_length = 0;
    if (headers.find("Content-Length") != headers.end()) 
        content_length = std::atoi(headers["Content-Length"].c_str());

    std::cerr << "DEBUG: Body length: " << content_length << "\n";
    std::cerr.flush();

    // Comprueba que el buffer se mayor q: las cabeceras, el delimitador (\r\n...) 
    // y el cuerpo de la solicitud
    if (buffer.length() >= header_end + 4 + content_length) 
    {
         /*// extrae el contenido del cuerpo de la solicitud ej:
            POST /cgi-bin/hello.php HTTP/1.1                    <--- LINEA DE SOLICITUD
            Host: localhost                                     <--- CABECERA
            Content-Type: application/x-www-form-urlencoded     <--- CABECERA
            Content-Length: 17                                  <--- CABECERA
            // BODY:
            name=Juan&age=30                                    <--- BODY   */
        body = buffer.substr(header_end + 4, content_length);
        
        // actualiza el buffer 
            // elimina las partes procesadas y solo guarda el body
        buffer = buffer.substr(header_end + 4 + content_length);
        std::cerr << "DEBUG: Parsed request successfully\n";
        std::cerr.flush();

        // Como la solicitud esta completa:
            // cabeceras + cuerpo
            // devuelve true
        return true;
    }

    std::cerr << "DEBUG: Incomplete request, waiting for body\n";
    std::cerr.flush();
    return false;
}

void Request::parseRequest(const std::string& raw_request) 
{
    // convierte el string const a string normal para poder trabajar sobre él
    std::string buffer = raw_request;
    parse(buffer);
}

std::string Request::getMethod() const 
{ 
    return method; 
}
std::string Request::getUri() const 
{ 
    return uri; 
}
std::string Request::getQuery() const 
{ 
    return query; 
}
std::string Request::getHeader(const std::string& key) const 
{
    std::map<std::string, std::string>::const_iterator it = headers.find(key);
    return it != headers.end() ? it->second : "";
}
std::string Request::getBody() const 
{ 
    return body; 
}

bool Request::isKeepAlive() const 
{
    std::string connection = getHeader("Connection");
    return connection.empty() || connection == "keep-alive";
}