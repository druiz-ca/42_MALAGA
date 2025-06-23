#include "Config.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

Config::Config(const std::string& filename) {
    std::cerr << "DEBUG: Parsing config file: " << filename << std::endl;
    std::cerr.flush(); // hace que se imprima el mensaje immediatamente y no se quede en el buffer
    parse(filename);
}

const std::vector<ServerConfig>& Config::getServers() const {
    return servers;
}

std::string Config::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r;");
    return str.substr(first, last - first + 1);
}

/* Lee y analiza el archivo de conf y guarda todos los datos
para que el servido web sepa como funcionar */
void Config::parse(const std::string& filename) {
    // Crea objeto donde almancena el nombre del archivo de string a const char)
    std::ifstream file(filename.c_str());
    
    // Comprueba si se ha podido abrir
    if (!file.is_open()) {
        std::cerr << "DEBUG: Could not open config file: " << filename << std::endl;
        std::cerr.flush();
        throw std::runtime_error("Could not open config file: " + filename);
    }

    std::string line;
    // Recorre cada linea del archivo
    while (std::getline(file, line)) 
    {
        // limpia cada linea de esapcios al inicio y final
        line = trim(line);
        
        // ignora linear vacias o comentarios
        if (line.empty() || line[0] == '#') continue;

        // Cuando encuentra el inicio de un bloque de servidor
        if (line.find("server") == 0 && line.find('{') != std::string::npos) 
        {
            // crea un objeto serverConfig
            ServerConfig server;

            // Parsea el bloque server (desde esa linea en adelante hasta que acaba el bloque)
            parseServer(file, line, server);

            // Añade ese servidor al vector servers
            servers.push_back(server);

            //Muestra toda la info del servidor que ha leído
            std::cerr << "DEBUG: Parsed server with port: " << server.port << ", root: " << server.root << ", index: " << server.index << std::endl;
            std::cerr.flush();
        }
    }
    
    // Cierra el objeto file
    file.close();
}

/* Lee un archivo de conf de servidor y asigna los valores correspondientes al objeto server. Si encuentra un bloque location
 usa parseLocation para procesarlo y añadirlo a la lista de locations del servidor */
void Config::parseServer(std::ifstream& file, std::string& line, ServerConfig& server) 
{
    // Asigno valores x defecto al objeto server
    server.root = "./www";
    server.index = "index.html";
    server.max_body_size = 1048576;
    server.port = 8080;

    // lee el archivo línea a línea
    while (std::getline(file, line)) 
    {
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;
        if (line == "}") break;

        if (line.find("location") == 0 && line.find('{') != std::string::npos) 
        {
            LocationConfig location;
            std::istringstream iss(line);
            std::string token, path;
            iss >> token >> path;
            location.path = trim(path);
            location.root = server.root; // Valor por defecto
            location.index = server.index; // Valor por defecto
            parseLocation(file, line, location);

            // Añade el objeto location al vector locations del servidor
            server.locations.push_back(location);

            // Imprimo toda la información sobre location, rutas, etc
            std::cerr << "DEBUG: Parsed location: " << location.path << ", root: " << location.root << ", index: " << location.index << ", methods: ";
            for (size_t i = 0; i < location.methods.size(); ++i)
                std::cerr << location.methods[i] << " ";
            std::cerr << ", cgi_path: " << location.cgi_path << ", upload_path: " << location.upload_path << std::endl;
            std::cerr.flush();

            // Para pasar a la siguiente linea
            continue;
        }

        // convierte line en stringstream para separar clave-valor
        std::istringstream iss(line);

        // Crea strings clave valor
        std::string key, value;

        // Extrae la clave del stringstream y la asigna a key
        iss >> key;

        // Extrae del stringstream el valor y lo asigna a valor
            // no podria hacer iss >> key >> value ?
        std::getline(iss, value);

        // limpia de espacios el valor (al inicio y final)
        value = trim(value);

        // Imprime la directiva (clave - valor)
        std::cerr << "DEBUG: Parsing server directive: " << key << " = " << value << std::endl;

        // Lo imprime en el acto para no dejarlo en el buffer
        std::cerr.flush();

        // Si la clave es "listen" convierte el valor a int y lo asigna a port
        if (key == "listen") server.port = std::atoi(value.c_str());
        else if (key == "host") server.host = value;
        else if (key == "server_name") server.server_name = value;
        else if (key == "root") server.root = value;
        else if (key == "index") server.index = value;
        else if (key == "error_page") 
        {
            // convierte el valor en stringstream
            std::istringstream value_iss(value);
            int code;
            std::string path;

            // separa el valor en code(404) y la ruta
            value_iss >> code >> path;

            // Guarda el error en la página de errores
                // limpiando de espacios la ruta
            server.error_pages[code] = trim(path);
        }
        // si la clave es max... convierte el valor a int y lo asigna a max....
        else if (key == "max_body_size") server.max_body_size = std::atoi(value.c_str());
    }
}

void Config::parseLocation(std::ifstream& file, std::string& line, LocationConfig& location) 
{
    while (std::getline(file, line)) 
    {
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;
        if (line == "}") break;

        std::istringstream iss(line);
        std::string key, value;
        iss >> key;
        std::getline(iss, value);
        value = trim(value);

        std::cerr << "DEBUG: Parsing location directive: " << key << " = " << value << std::endl;
        std::cerr.flush();
        if (key == "methods") 
        {
            std::istringstream value_iss(value);
            std::string method;
            while (value_iss >> method) 
                location.methods.push_back(trim(method));
        }
        else if (key == "root") location.root = value;
        else if (key == "index") location.index = value;
        else if (key == "upload_path") location.upload_path = value;
        else if (key == "cgi_path") location.cgi_path = value;
        else if (key == "redirect") location.redirect = value;
    }
}

/* EJEMPLO DE ARCHIVO DE CONF
# Archivo de configuración de ejemplo

server {
    listen 8080
    host 127.0.0.1
    server_name mi_servidor
    root /var/www/html
    index index.html
    error_page 404 /errors/404.html
    max_body_size 2097152

    location / {
        root /var/www/html
        index index.html
        methods GET POST
    }

    location /imagenes {
        root /var/www/imagenes
        index index.png
        methods GET
        upload_path /uploads
    }

    location /cgi-bin {
        cgi_path /usr/bin/python3
        methods GET POST
    }
}
*/