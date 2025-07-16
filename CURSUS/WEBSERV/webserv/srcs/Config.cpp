#include "Config.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <unistd.h> // Para access
#include <cstring>  // Para strerror

Config::Config() {}

std::string Config::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n;");
    if (start == std::string::npos) return "";
    return str.substr(start, end - start + 1);
}

void Config::load(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "ERROR: Failed to open config file: " << filename 
                  << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl;
        throw std::runtime_error("Failed to open config file: " + filename);
    }
    std::cerr << "DEBUG: Opened config file: " << filename << std::endl;

    std::string line;
    ServerConfig current_server;
    LocationConfig current_location;
    bool in_server_block = false;
    bool in_location_block = false;

    while (std::getline(file, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;

        std::cerr << "DEBUG: Processing line: " << line << std::endl;

        std::istringstream iss(line);
        std::string key;
        iss >> key;

        if (key == "server" && line.find("{") != std::string::npos) {
            if (in_server_block) {
                std::cerr << "ERROR: Nested server block detected" << std::endl;
                throw std::runtime_error("Nested server blocks are not allowed");
            }
            in_server_block = true;
            current_server = ServerConfig();
            std::cerr << "DEBUG: Starting server block" << std::endl;
            continue;
        }

        if (in_server_block && line == "}") {
            if (in_location_block) {
                // Validar cgi_paths antes de añadir la ubicación
                for (std::map<std::string, std::string>::iterator it = current_location.cgi_paths.begin();
                     it != current_location.cgi_paths.end(); ++it) {
                    if (access(it->second.c_str(), X_OK) != 0) {
                        std::cerr << "ERROR: CGI interpreter not found or not executable: " << it->second 
                                  << " for extension " << it->first 
                                  << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl;
                        throw std::runtime_error("Invalid CGI interpreter: " + it->second);
                    }
                    std::cerr << "DEBUG: Validated CGI interpreter: " << it->second << " for extension " << it->first << std::endl;
                }
                current_server.locations.push_back(current_location);
                in_location_block = false;
                std::cerr << "DEBUG: Added location block: " << current_location.path << std::endl;
            } else {
                if (current_server.ports.empty()) {
                    std::cerr << "ERROR: No ports defined for server block" << std::endl;
                    throw std::runtime_error("No ports defined for server block");
                }
                // Validar root
                if (current_server.root.empty()) {
                    std::cerr << "WARNING: No root defined for server block, using default '/var/www/html'" << std::endl;
                    current_server.root = "/var/www/html";
                }
                if (access(current_server.root.c_str(), R_OK) != 0) {
                    std::cerr << "ERROR: Root directory not accessible: " << current_server.root 
                              << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl;
                    throw std::runtime_error("Root directory not accessible: " + current_server.root);
                }
                servers.push_back(current_server);
                in_server_block = false;
                std::cerr << "DEBUG: Added server block with ports: ";
                for (size_t i = 0; i < current_server.ports.size(); ++i) {
                    std::cerr << current_server.ports[i] << " ";
                }
                std::cerr << std::endl;
            }
            continue;
        }

        if (in_server_block && key == "location" && line.find("{") != std::string::npos) {
            if (in_location_block) {
                std::cerr << "ERROR: Nested location block detected" << std::endl;
                throw std::runtime_error("Nested location blocks are not allowed");
            }
            std::string path;
            size_t path_start = line.find_first_not_of(" \t", key.length());
            size_t path_end = line.find("{", path_start);
            if (path_start == std::string::npos || path_end == std::string::npos) {
                std::cerr << "ERROR: Invalid location directive syntax: " << line << std::endl;
                throw std::runtime_error("Invalid location directive syntax");
            }
            path = trim(line.substr(path_start, path_end - path_start));
            in_location_block = true;
            current_location = LocationConfig();
            current_location.path = path;
            std::cerr << "DEBUG: Starting location block for path: " << path << std::endl;
            continue;
        }

        if (in_location_block && line == "}") {
            // Validar cgi_paths antes de cerrar
            for (std::map<std::string, std::string>::iterator it = current_location.cgi_paths.begin();
                 it != current_location.cgi_paths.end(); ++it) {
                if (access(it->second.c_str(), X_OK) != 0) {
                    std::cerr << "ERROR: CGI interpreter not found or not executable: " << it->second 
                              << " for extension " << it->first 
                              << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl;
                    throw std::runtime_error("Invalid CGI interpreter: " + it->second);
                }
                std::cerr << "DEBUG: Validated CGI interpreter: " << it->second << " for extension " << it->first << std::endl;
            }
            current_server.locations.push_back(current_location);
            in_location_block = false;
            std::cerr << "DEBUG: Added location block: " << current_location.path << std::endl;
            continue;
        }

        if (in_location_block) {
            if (key == "root") {
                current_location.root = trim(iss.str().substr(iss.tellg()));
                std::cerr << "DEBUG: Set location root: " << current_location.root << std::endl;
            } else if (key == "index") {
                current_location.index = trim(iss.str().substr(iss.tellg()));
                std::cerr << "DEBUG: Set location index: " << current_location.index << std::endl;
            } else if (key == "cgi_path") {
                std::string token;
                while (iss >> token) {
                    // Cada token debe tener el formato extension=interpreter
                    size_t equals_pos = token.find('=');
                    if (equals_pos == std::string::npos || equals_pos == 0 || equals_pos == token.length() - 1) {
                        std::cerr << "ERROR: Invalid cgi_path syntax in token: " << token << std::endl;
                        throw std::runtime_error("Invalid cgi_path syntax: " + token);
                    }
                    std::string extension = token.substr(0, equals_pos);
                    std::string interpreter = token.substr(equals_pos + 1);
                    if (extension.empty() || interpreter.empty()) {
                        std::cerr << "ERROR: Empty extension or interpreter in cgi_path: " << token << std::endl;
                        throw std::runtime_error("Invalid cgi_path syntax: " + token);
                    }
                    current_location.cgi_paths[extension] = interpreter;
                    std::cerr << "DEBUG: Added cgi_path: " << extension << " -> " << interpreter << std::endl;
                }
                if (current_location.cgi_paths.empty()) {
                    std::cerr << "ERROR: No valid cgi_path entries found in: " << line << std::endl;
                    throw std::runtime_error("No valid cgi_path entries");
                }
            } else if (key == "upload_path") {
                current_location.upload_path = trim(iss.str().substr(iss.tellg()));
                std::cerr << "DEBUG: Set upload_path: " << current_location.upload_path << std::endl;
            } else if (key == "directory_listing") {
                std::string value;
                iss >> value;
                current_location.directory_listing = (value == "on");
                std::cerr << "DEBUG: Set directory_listing: " << (current_location.directory_listing ? "on" : "off") << std::endl;
            } else if (key == "client_max_body_size") {
                std::string value;
                iss >> value;
                std::istringstream converter(value);
                unsigned long size;
                if (!(converter >> size)) {
                    std::cerr << "ERROR: Invalid client_max_body_size: " << value << std::endl;
                    throw std::runtime_error("Invalid client_max_body_size");
                }
                current_location.client_max_body_size = size;
                std::cerr << "DEBUG: Set client_max_body_size: " << current_location.client_max_body_size << std::endl;
            } else if (key == "methods") {
                std::string method;
                current_location.methods.clear();
                while (iss >> method) {
                    current_location.methods.push_back(method);
                    std::cerr << "DEBUG: Added method: " << method << std::endl;
                }
            } else if (key == "redirect") {
                current_location.redirect = trim(iss.str().substr(iss.tellg()));
                std::cerr << "DEBUG: Set redirect: " << current_location.redirect << std::endl;
            } else {
                std::cerr << "WARNING: Unknown location directive: " << key << std::endl;
            }
        } else if (in_server_block) {
            if (key == "listen") {
                std::string port_str;
                while (iss >> port_str) {
                    std::istringstream converter(port_str);
                    int port;
                    if (!(converter >> port) || port <= 0 || port > 65535) {
                        std::cerr << "ERROR: Invalid port: " << port_str << std::endl;
                        throw std::runtime_error("Invalid port: " + port_str);
                    }
                    current_server.ports.push_back(port);
                    std::cerr << "DEBUG: Added port: " << port << std::endl;
                }
            } else if (key == "server_name") {
                current_server.server_name = trim(iss.str().substr(iss.tellg()));
                std::cerr << "DEBUG: Set server_name: " << current_server.server_name << std::endl;
            } else if (key == "root") {
                current_server.root = trim(iss.str().substr(iss.tellg()));
                std::cerr << "DEBUG: Set server root: " << current_server.root << std::endl;
            } else if (key == "index") {
                current_server.index = trim(iss.str().substr(iss.tellg()));
                std::cerr << "DEBUG: Set server index: " << current_server.index << std::endl;
            } else if (key == "client_max_body_size") {
                std::string value;
                iss >> value;
                std::istringstream converter(value);
                unsigned long size;
                if (!(converter >> size)) {
                    std::cerr << "ERROR: Invalid client_max_body_size: " << value << std::endl;
                    throw std::runtime_error("Invalid client_max_body_size");
                }
                current_server.client_max_body_size = size;
                std::cerr << "DEBUG: Set server client_max_body_size: " << current_server.client_max_body_size << std::endl;
            } else if (key == "error_page") {
                int code;
                std::string path;
                iss >> code >> path;
                current_server.error_pages[code] = path;
                std::cerr << "DEBUG: Added error_page: " << code << " -> " << path << std::endl;
            } else {
                std::cerr << "WARNING: Unknown server directive: " << key << std::endl;
            }
        } else {
            std::cerr << "ERROR: Directive outside server block: " << key << std::endl;
            throw std::runtime_error("Directive outside server block: " + key);
        }
    }

    if (in_server_block) {
        if (in_location_block) {
            // Validar cgi_paths antes de cerrar
            for (std::map<std::string, std::string>::iterator it = current_location.cgi_paths.begin();
                 it != current_location.cgi_paths.end(); ++it) {
                if (access(it->second.c_str(), X_OK) != 0) {
                    std::cerr << "ERROR: CGI interpreter not found or not executable: " << it->second 
                              << " for extension " << it->first 
                              << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl;
                    throw std::runtime_error("Invalid CGI interpreter: " + it->second);
                }
                std::cerr << "DEBUG: Validated CGI interpreter: " << it->second << " for extension " << it->first << std::endl;
            }
            current_server.locations.push_back(current_location);
            std::cerr << "DEBUG: Added final location block: " << current_location.path << std::endl;
        }
        if (current_server.ports.empty()) {
            std::cerr << "ERROR: No ports defined for final server block" << std::endl;
            throw std::runtime_error("No ports defined for final server block");
        }
        // Validar root
        if (current_server.root.empty()) {
            std::cerr << "WARNING: No root defined for final server block, using default '/var/www/html'" << std::endl;
            current_server.root = "/var/www/html";
        }
        if (access(current_server.root.c_str(), R_OK) != 0) {
            std::cerr << "ERROR: Root directory not accessible: " << current_server.root 
                      << ", errno: " << errno << " (" << strerror(errno) << ")" << std::endl;
            throw std::runtime_error("Root directory not accessible: " + current_server.root);
        }
        servers.push_back(current_server);
        std::cerr << "DEBUG: Added final server block with ports: ";
        for (size_t i = 0; i < current_server.ports.size(); ++i) {
            std::cerr << current_server.ports[i] << " ";
        }
        std::cerr << std::endl;
    }

    if (servers.empty()) {
        std::cerr << "ERROR: No server blocks defined in config file" << std::endl;
        throw std::runtime_error("No server blocks defined in config file");
    }

    file.close();
    std::cerr << "DEBUG: Config file loaded successfully, total servers: " << servers.size() << std::endl;
}