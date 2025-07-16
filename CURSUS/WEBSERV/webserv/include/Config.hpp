#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <vector>
#include <map>

struct LocationConfig {
    std::string path;
    std::string root;
    bool directory_listing;
    std::map<std::string, std::string> cgi_paths; // extension -> interpreter
    std::vector<std::string> methods;
    std::string upload_path;
    std::string index;
    std::string redirect;
    size_t client_max_body_size;

    LocationConfig() : directory_listing(false), index(""), redirect(""), client_max_body_size(1048576) {}
};

struct ServerConfig {
    std::vector<int> ports; // Cambiado de int port a vector de puertos
    std::string server_name;
    std::string root;
    std::string index;
    std::map<int, std::string> error_pages;
    std::vector<LocationConfig> locations;
    size_t client_max_body_size;

    ServerConfig() : client_max_body_size(1048576) {}
};

class Config {
private:
    std::vector<ServerConfig> servers;

public:
    Config();
    void load(const std::string& filename);
    const std::vector<ServerConfig>& getServers() const { return servers; }
    std::string trim(const std::string& str);
};

#endif