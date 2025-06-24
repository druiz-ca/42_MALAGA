#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Location_config
{
    vector<string> methods;
    string root;
    string index;
    string upload_path;
    string cgi_path;
    string redirect;
};

struct Server_config
{
    int port;
    string host;
    string server_name;
    string root;
    string index;
    size_t max_body_size;
    map<int, string> error_page;

    // +o- es un array dinámico de estructuras Location
    vector<Location_config> locations;

};

class Config
{
    public:
        Config(const string&);
        const vector<Server_config>& getServers() const;

    private:
        vector<Server_config> servers;
        void parse(const string&);
        void parseServer(ifstream& file, string& line, Server_config& server);
        void parseLocation(ifstream& file, string& line, Location_config& location);
        string trim(const string& str);
};