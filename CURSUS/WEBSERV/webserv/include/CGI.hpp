#ifndef CGI_HPP
#define CGI_HPP

#include "Request.hpp"
#include "Config.hpp"
#include <string>
#include <utility> // Para std::pair

class CGI {
private:
    const Request& request;
    const LocationConfig& location;
    const ServerConfig& config;
    int server_port;

public:
    CGI(const Request& req, const LocationConfig& loc, const ServerConfig& cfg, int port);
    std::pair<std::string, int> execute(const std::string& script_path);
};

#endif