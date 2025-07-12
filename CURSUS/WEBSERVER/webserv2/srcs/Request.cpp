#include "Request.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

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
    std::cerr << "DEBUG: Parsing buffer: " << buffer << "\n";
    std::cerr.flush();

    // Check if buffer contains end of headers
    size_t header_end = buffer.find("\r\n\r\n");
    if (header_end == std::string::npos) 
    {
        std::cerr << "DEBUG: Incomplete request, missing \\r\\n\\r\\n\n";
        std::cerr.flush();
        return false;
    }

    // Extract headers
    std::string header = buffer.substr(0, header_end);
    std::istringstream iss(header);
    std::string line;
    bool first_line = true;

    while (std::getline(iss, line)) 
    {
        if (line.empty() || line == "\r") 
            continue;
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());

        if (first_line) 
        {
            std::istringstream line_ss(line);
            line_ss >> method >> uri >> protocol;
            if (method.empty() || uri.empty() || protocol.empty()) 
            {
                std::cerr << "DEBUG: Invalid request line: " << line << "\n";
                std::cerr.flush();
                return false;
            }
            size_t query_pos = uri.find('?');
            if (query_pos != std::string::npos) 
            {
                query = uri.substr(query_pos + 1);
                uri = uri.substr(0, query_pos);
            }
            std::cerr << "DEBUG: Parsed method: " << method << ", uri: " << uri << ", query: " << query << ", protocol: " << protocol << "\n";
            std::cerr.flush();
            first_line = false;
        } else {
            size_t colon = line.find(": ");
            if (colon != std::string::npos) 
            {
                std::string key = line.substr(0, colon);
                std::string value = line.substr(colon + 2);
                headers[key] = value;
                std::cerr << "DEBUG: Header " << key << ": " << value << "\n";
                std::cerr.flush();
            }
        }
    }

    // Extract body if present
    size_t content_length = 0;
    if (headers.find("Content-Length") != headers.end()) 
        content_length = std::atoi(headers["Content-Length"].c_str());
    std::cerr << "DEBUG: Body length: " << content_length << "\n";
    std::cerr.flush();

    if (buffer.length() >= header_end + 4 + content_length) 
    {
        body = buffer.substr(header_end + 4, content_length);
        buffer = buffer.substr(header_end + 4 + content_length);
        std::cerr << "DEBUG: Parsed request successfully\n";
        std::cerr.flush();
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

std::string Request::getMethod() const { return method; }
std::string Request::getUri() const { return uri; }
std::string Request::getQuery() const { return query; }
std::string Request::getHeader(const std::string& key) const 
{
    std::map<std::string, std::string>::const_iterator it = headers.find(key);
    return it != headers.end() ? it->second : "";
}
std::string Request::getBody() const { return body; }

bool Request::isKeepAlive() const 
{
    std::string connection = getHeader("Connection");
    return connection.empty() || connection == "keep-alive";
}