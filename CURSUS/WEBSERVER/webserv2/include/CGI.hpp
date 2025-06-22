#ifndef CGI_HPP
#define CGI_HPP

#include "Request.hpp"
#include "Config.hpp"
#include <string>
#include <vector>

class CGI {
private:
    const Request& request;
    const LocationConfig& location;

public:
    CGI(const Request& req, const LocationConfig& loc);
    std::string execute();
};

#endif