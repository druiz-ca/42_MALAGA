#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>
#include <map>

class Request {
private:
    std::string method;
    std::string uri;
    std::string query;
    std::string protocol;
    std::map<std::string, std::string> headers;
    std::string body;

    void parseRequest(const std::string& raw_request);

public:
    Request();
    Request(const std::string& raw_request);

    bool parse(std::string& buffer); // Método parse

    std::string getMethod() const;
    std::string getUri() const;
    std::string getQuery() const;
    std::string getHeader(const std::string& key) const;
    std::string getBody() const;
    bool isKeepAlive() const;
};

#endif
