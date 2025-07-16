#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>
#include <map>

class Request {
public:
    Request(int fd, const std::string& initial_data);
    void appendBody(const std::string& data);
    bool isComplete() const;
    std::string getMethod() const { return method; }
    std::string getUri() const { return uri; }
    std::string getQuery() const { return query; }
    std::string getVersion() const { return version; }
    std::string getBody() const;
    std::string getHeader(const std::string& key) const;

private:
    std::string method;
    std::string uri;
    std::string query;
    std::string version;
    std::map<std::string, std::string> headers;
    std::string body;
    std::string dechunked_body;
    bool body_complete;
    bool is_chunked;
    int client_fd;
    void dechunkBody();
    void processMultipartFormData();
};

#endif