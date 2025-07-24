#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include "Config.hpp"
#include "Request.hpp"
#include "CGI.hpp"
#include <string>
#include <map>

class Response {
public:
    Response(const Request& request, const ServerConfig& server_config);
    std::string generate();
    void setStatus(int code, const std::string& message);
    void setHeader(const std::string& key, const std::string& value);
    void setBody(const std::string& body_content);
    void handleRequest();

private:
    int status_code;
    std::string status_message;
    std::map<std::string, std::string> headers;
    std::string body;
    const Request& request;
    const ServerConfig& server_config;

    std::string cleanPath(const std::string& path) const;
    std::string cleanMethod(const std::string& method) const;
    std::string getContentType(const std::string& path);
    void handleGetRequest(const LocationConfig& location);
    void handlePostRequest(const LocationConfig& location);
    void handleDeleteRequest(const LocationConfig& location);
    void handleCgiRequest(const LocationConfig& location);
    const LocationConfig* findLocation(const std::string& uri) const;
};

#endif