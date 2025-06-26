#include "../includes/config.hpp"

Config::Config(const string& filepath)
{
    cerr << "Parsing filepath: " << filepath << endl;
    // tengo que llamar a parse desde aquí porque es un método privado
    parse(filepath);
}

/* Limpia:
    - espacios y saltos de línea al cominezo y final
    - puntos y coma al final si lo hay
*/
string Config::trim(const string& line)
{
    // Busca 1º char que no sea espacio, tab, o salto de l.
        // si solo encuentra esapcio, tab, etc devuelve npos
    size_t first = line.find_first_not_of(" \t\n\r");

    // Si no encuentra ningún char útil (si llega hasta el final del string)
    if (first == string::npos)
        return ""; // devuelve cadena vacía

    // busca ult. pos que no sea ....
    size_t last = line.find_last_not_of(" \t\n\r");

    // subst-> pos inicial, cantidad de chars
    return line.substr(first, last - first + 1);
}

void Config::parse(const string& filepath)
{
    // c_str convierte un tipo string a tipo const char*
    // crea objeto ifstream con la ruta como parámetro pq permite controlar
    //     si se ha abierto el archivo
    ifstream file(filepath.c_str());

    if (!file.is_open())
        throw runtime_error("Could not open config file: " + filepath);
    
    string line;
    while (getline(file, line))
    {   // me limpia el string de espacios
        
        line = trim(line);
        if (line.empty() || line[0] == '#' || line == "}")
            continue;
        if (line.find("server") == 0 && line.find('{') != string::npos)
        {
            Server_config server;
            parseServer(file, line, server);
            servers.push_back(server);
            cerr << "Root of server: " << server.root << endl;
            cerr << "Index of server: " << server.index << endl;
            cerr << "Max body of server: " << server.max_body_size << endl;
            cerr << "Port of server: " << server.port << endl;

        }
        else
            throw runtime_error("Error: file not contains server bloq");
    }
    file.close();
}

void Config::parseServer(ifstream &file, string &line, Server_config& server)
{
    server.root = "./www";
    server.index = "index.html";
    server.max_body_size = 1048576;
    server.port = 8080;

    while (getline(file, line))
    {
        line = trim(line);
        if (line.empty() || line[0] == '#')
            continue;
        if (line == "}")
            break;
        if (line.find("location") == 0 && line.find('{') != string::npos)
        {
            
        }
    }
}