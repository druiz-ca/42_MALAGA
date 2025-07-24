#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <vector>
#include <map>
#include <fstream>

/* ESTRUCTURA PARA LA CONF DE UNA RUTA ESPECIFICA*/
struct LocationConfig {
    std::string path; // /images, /api

    // para métodos HTTP para la ruta (GET, POST, etc)
    std::vector<std::string> methods; // 
    std::string root; // raiz del sistema de archivos
    std::string index; // index.html
    std::string upload_path; // donde se guardan archivos subidos
    std::string cgi_path; // ruta para el ejecutable CGI
    std::string redirect;
};

/* ESTRUCTURA GENERAL DE LA CONF DEL SERVIDOR */
struct ServerConfig {
    int port; // puerto donde el servidor escucha
    std::string host; // IP o nombre del host donde escucha
    std::string server_name;
    std::string root;
    std::string index;
    size_t max_body_size;// para limitar tamaño d archivos subidos
    std::map<int, std::string> error_pages;
    std::vector<LocationConfig> locations;
};

class Config {
public:
    Config(const std::string& filename);
    const std::vector<ServerConfig>& getServers() const;

private:
    std::vector<ServerConfig> servers;
    void parse(const std::string& filename);
    void parseServer(std::ifstream& file, std::string& line, ServerConfig& server);
    void parseLocation(std::ifstream& file, std::string& line, LocationConfig& location);
    std::string trim(const std::string& str);
};

#endif