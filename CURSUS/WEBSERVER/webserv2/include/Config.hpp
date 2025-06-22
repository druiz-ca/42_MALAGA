#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <vector>
#include <map>
#include <fstream>

struct LocationConfig {
    std::string path;
    std::vector<std::string> methods;
    std::string root;
    std::string index;
    std::string upload_path;
    std::string cgi_path;
    std::string redirect;
};

struct ServerConfig {
    int port;
    std::string host;
    std::string server_name;
    std::string root;
    std::string index;
    size_t max_body_size;
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