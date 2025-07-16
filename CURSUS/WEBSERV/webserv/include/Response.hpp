#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include "Request.hpp"
#include "Config.hpp"
#include <string>
#include <map>

class Response {
public:
    Response(const Request& req, const ServerConfig& config, int port);  // Constructor with request, config and port
    std::string handleRequest();  // Main method to handle HTTP requests

private:
    const Request& request;  // Reference to the HTTP request
    const ServerConfig& config;  // Reference to server configuration
    int port;  // Client connection port
    int status_code;  // HTTP response status code

    std::string trim(const std::string& str) const;  // Remove whitespace from string
    const LocationConfig* findLocation(const std::string& uri) const;  // Find matching location config
    bool fileExists(const std::string& path) const;  // Check if file exists
    bool isDirectory(const std::string& path) const;  // Check if path is directory
    std::string getMimeType(const std::string& path) const;  // Get MIME type from file extension
    std::string generateDirectoryListing(const std::string& path, const std::string& uri) const;  // Generate HTML directory listing
    std::string readFile(const std::string& path) const;  // Read file content safely
    std::string handleUpload(const std::string& upload_path);  // Handle file upload via POST
    std::string resolvePath(const LocationConfig* location) const;  // Resolve final file path
};

#endif