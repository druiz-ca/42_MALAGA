#include "Response.hpp"
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <iostream>
#include <cstdlib>
#include <string.h>



Response::Response(const Request& req, const ServerConfig& conf)
    : status_code(200), status_message("OK"), request(req), server_config(conf) {
    std::cerr << "DEBUG: Response constructor called for method: " << req.getMethod() << ", URI: " << req.getUri() << std::endl;
    std::cerr.flush();
}

void Response::handleRequest() {
    const LocationConfig* location = findLocation(request.getUri());
    std::cerr << "DEBUG: Handling request for URI: " << request.getUri() << std::endl;
    std::cerr.flush();

    if (!location) {
        status_code = 404;
        status_message = "Not Found";
        setBody("<h1>404 Not Found</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        std::cerr << "DEBUG: No location found, returning 404" << std::endl;
        std::cerr.flush();
        return;
    }

    if (!location->redirect.empty()) {
        status_code = 301;
        status_message = "Moved Permanently";
        setHeader("Location", location->redirect);
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        return;
    }

    if (request.getMethod() == "GET" && !location->cgi_path.empty()) {
        handleCgiRequest(*location);
    } else if (request.getMethod() == "POST" && !location->cgi_path.empty()) {
        handleCgiRequest(*location);
    } else if (request.getMethod() == "GET") {
        handleGetRequest(*location);
    } else if (request.getMethod() == "POST") {
        handlePostRequest(*location);
    } else if (request.getMethod() == "DELETE") {
        handleDeleteRequest(*location);
    } else {
        status_code = 405;
        status_message = "Method Not Allowed";
        setBody("<h1>405 Method Not Allowed</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        std::cerr << "DEBUG: Method not supported: " << request.getMethod() << std::endl;
        std::cerr.flush();
    }
}

void Response::handleGetRequest(const LocationConfig& location) {
    std::string path = cleanPath(location.root + "/" + (request.getUri() == "/" ? location.index : request.getUri().substr(location.path.length())));
    std::cerr << "DEBUG: Handling GET request for path: " << path << std::endl;
    std::cerr.flush();

    struct stat st;
    if (stat(path.c_str(), &st) != 0 || !S_ISREG(st.st_mode)) {
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
    if (!file.is_open()) {
        status_code = 403;
        status_message = "Forbidden";
        setBody("<h1>403 Forbidden</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        std::cerr << "DEBUG: Unable to open file: " << path << std::endl;
        std::cerr.flush();
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    setBody(buffer.str());
    setHeader("Content-Type", getContentType(path));
    setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
    std::cerr << "DEBUG: File served successfully: " << path << std::endl;
    std::cerr.flush();
}

void Response::handlePostRequest(const LocationConfig& location) {
    std::cerr << "DEBUG: Handling POST request with upload_path: " << location.upload_path << std::endl;
    std::cerr.flush();
    if (location.upload_path.empty()) {
        status_code = 403;
        status_message = "Forbidden";
        setBody("<h1>403 Forbidden</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        std::cerr << "DEBUG: No upload_path specified" << std::endl;
        std::cerr.flush();
        return;
    }

    std::string filename = request.getUri().substr(request.getUri().find_last_of('/') + 1);
    if (filename.empty()) {
        status_code = 400;
        status_message = "Bad Request";
        setBody("<h1>400 Bad Request</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        std::cerr << "DEBUG: No filename provided" << std::endl;
        std::cerr.flush();
        return;
    }

    std::string path = cleanPath(location.upload_path + "/" + filename);
    std::cerr << "DEBUG: Uploading file to: " << path << std::endl;
    std::cerr.flush();
    std::ofstream file(path.c_str());
    if (!file.is_open()) {
        status_code = 403;
        status_message = "Forbidden";
        setBody("<h1>403 Forbidden</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        std::cerr << "DEBUG: Unable to open file for writing: " << path << std::endl;
        std::cerr.flush();
        return;
    }

    file << request.getBody();
    file.close();
    status_code = 201;
    status_message = "Created";
    setBody("<h1>201 Created</h1>");
    setHeader("Content-Type", "text/html");
    setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
    std::cerr << "DEBUG: File uploaded successfully: " << path << std::endl;
    std::cerr.flush();
}

void Response::handleDeleteRequest(const LocationConfig& location) {
    std::string path = cleanPath(location.root + "/" + request.getUri().substr(location.path.length()));
    std::cerr << "DEBUG: Handling DELETE request for path: " << path << std::endl;
    std::cerr.flush();

    struct stat st;
    if (stat(path.c_str(), &st) != 0 || !S_ISREG(st.st_mode)) {
        status_code = 404;
        status_message = "Not Found";
        setBody("<h1>404 Not Found</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        std::cerr << "DEBUG: File not found or not a regular file: " << path << std::endl;
        std::cerr.flush();
        return;
    }

    if (unlink(path.c_str()) != 0) {
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

void Response::handleCgiRequest(const LocationConfig& location) {
    if (!location.methods.empty()) {
        bool method_allowed = false;
        std::cerr << "DEBUG: Checking allowed methods for " << request.getMethod() << std::endl;
        std::cerr.flush();
        for (size_t i = 0; i < location.methods.size(); ++i) {
            std::string method = cleanMethod(location.methods[i]);
            std::cerr << "DEBUG: Method " << method << std::endl;
            std::cerr.flush();
            if (method == request.getMethod()) {
                method_allowed = true;
                break;
            }
        }
        if (!method_allowed) {
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
    CGI cgi(request, location);
    std::string output = cgi.execute();
    if (output.empty()) {
        std::cerr << "DEBUG: CGI output is empty" << std::endl;
        std::cerr.flush();
        status_code = 500;
        status_message = "Internal Server Error";
        setBody("<h1>500 Internal Server Error</h1>");
        setHeader("Content-Type", "text/html");
        setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
        return;
    }

    setBody(output);
    setHeader("Content-Type", "text/html");
    setHeader("Connection", request.isKeepAlive() ? "keep-alive" : "close");
    std::cerr << "DEBUG: CGI executed successfully" << std::endl;
    std::cerr.flush();
}

const LocationConfig* Response::findLocation(const std::string& uri) const {
    const std::vector<LocationConfig>& locations = server_config.locations;
    const LocationConfig* best_match = NULL;
    size_t longest_match = 0;

    std::string normalized_uri = uri;
    if (!normalized_uri.empty() && normalized_uri[0] == '/') {
        normalized_uri = normalized_uri.substr(1);
    }

    std::cerr << "DEBUG: Finding location for URI: " << uri << ", normalized: " << normalized_uri << std::endl;
    std::cerr.flush();
    for (size_t i = 0; i < locations.size(); ++i) {
        std::string path = cleanPath(locations[i].path);
        if (path[0] == '/') {
            path = path.substr(1);
        }
        std::cerr << "DEBUG: Checking location path: " << path << " (original: " << locations[i].path << "), methods: ";
        for (size_t j = 0; j < locations[i].methods.size(); ++j) {
            std::cerr << locations[i].methods[j] << " ";
        }
        std::cerr << ", root: " << locations[i].root << ", upload_path: " << locations[i].upload_path << ", cgi_path: " << locations[i].cgi_path << std::endl;
        std::cerr.flush();

        // Check if the normalized URI starts with the location path
        if (path.empty() || normalized_uri.find(path) == 0) {
            // Ensure the match is either exact or followed by a slash or end of string
            if (normalized_uri.length() == path.length() || 
                normalized_uri[path.length()] == '/' || 
                normalized_uri[path.length()] == '\0') {
                if (path.length() >= longest_match) {
                    longest_match = path.length();
                    best_match = &locations[i];
                    std::cerr << "DEBUG: New best match: " << locations[i].path << std::endl;
                    std::cerr.flush();
                }
            }
        }
    }
    
    if (best_match) {
        std::cerr << "DEBUG: Selected location: " << best_match->path << ", root: " << cleanPath(best_match->root) << ", index: " << cleanPath(best_match->index) << std::endl;
        std::cerr.flush();
    } else {
        std::cerr << "DEBUG: No location found for URI: " << uri << "\n";
        std::cerr.flush();
    }
    return best_match;
}

std::string Response::cleanPath(const std::string& path) const {
    std::string result = path;
    while (result.find("//") != std::string::npos) {
        result.replace(result.find("//"), 2, "/");
    }
    if (!result.empty() && result[result.length() - 1] == '/') {
        result = result.substr(0, result.length() - 1);
    }
    return result;
}

std::string Response::cleanMethod(const std::string& method) const {
    std::string result = method;
    size_t pos = result.find_first_of(" \t\n\r");
    if (pos != std::string::npos) {
        result = result.substr(0, pos);
    }
    return result;
}

void Response::setHeader(const std::string& key, const std::string& value) {
    headers[key] = value;
}

void Response::setBody(const std::string& b) {
    body = b;
    std::ostringstream oss;
    oss << body.length();
    setHeader("Content-Length", oss.str());
}

std::string Response::generate() {
    std::ostringstream response;
    response << "HTTP/1.1 " << status_code << " " << status_message << "\r\n";
    for (std::map<std::string, std::string>::const_iterator it = headers.begin(); it != headers.end(); ++it) {
        response << it->first << ": " << it->second << "\r\n";
    }
    response << "\r\n" << body;
    std::cerr << "DEBUG: Generated response: " << response.str() << std::endl;
    std::cerr.flush();
    return response.str();
}

std::string Response::getContentType(const std::string& path) {
    if (path.rfind(".html") != std::string::npos) return "text/html";
    if (path.rfind(".css") != std::string::npos) return "text/css";
    if (path.rfind(".js") != std::string::npos) return "application/javascript";
    if (path.rfind(".jpg") != std::string::npos || path.rfind(".jpeg") != std::string::npos) return "image/jpeg";
    if (path.rfind(".png") != std::string::npos) return "image/png";
    if (path.rfind(".php") != std::string::npos) return "text/html";
    return "text/plain";
}