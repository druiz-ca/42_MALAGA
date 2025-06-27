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
        if (line.empty() || line[0] == '#')
            continue;
        if (line.find("server") == 0 && line.find('{') != string::npos)
        {
            Server_config server;
            parseServer(file, line, server);
            servers.push_back(server);
        }
    }
    file.close();
}

void Config::parseServer(ifstream &file, string &line, Server_config& server)
{
    // ------------- ASIGN PREDETERMINATE DIRECTIVES ----------------
    server.root = "./www";
    server.index = "index.html";
    server.max_body_size = 1048576;
    server.port = 8080;

    cerr << "Asign predeterminate directives :"<< endl;
    cerr << "- Root of server: " << server.root << endl;
    cerr << "- Index of server: " << server.index << endl;
    cerr << "- Max body of server: " << server.max_body_size << endl;
    cerr << "- Port of server: " << server.port << endl << endl;

    while (getline(file, line))
    {
        line = trim(line);
        if (line.empty() || line[0] == '#')
        continue;
        if (line == "}")
            break;
        if (line.find("location") == 0 && line.find('{') != string::npos)
        {
            Location_config location; //x cada location crea un objeto
            istringstream iss(line);
            string token, path;
            
            iss >> token >> path;
            location.path = trim(path); // asigno la ruta location
            
            // ----------- Asigno valores x defecto del servidor
            location.root = server.root;
            location.index = server.index;

            parseLocation(file, line, location);
            
            server.locations.push_back(location);
            
            cerr << "ServerParsed location: " << endl;
            cerr << "- path: " << location.path << endl;
            cerr << "- root: " << location.root << endl;
            cerr << "- index: " << location.index << endl;
            cerr << "- cgi_path: " << location.cgi_path << endl;
            cerr << "- upload_path: " << location.upload_path << endl;
            cerr << "- methods: ";
            for (size_t i = 0; i < location.methods.size(); i++)
                cerr << location.methods[i] << " ";
            cerr << endl << endl;
        }
        // ------------------ MINIPARSEO DE DIRECTIVAS ---------------------
        istringstream iss(line);
        string key, value;
        iss >> key >> value; // vuelvo a usar >> en vez de getline 
        value = trim(value);
            
        // ========================== DIRECTIVAS =========================
        // ------------------ IMPRESION DE DIRECTIVAS ---------------------
        cerr << GREEN << "SERVER PARSING DIRECTIVES: " << key << " = " << value << RESET << endl;
        // ------------------- ASIGNACIÓN DE DIRECTIVAS -------------------
        if (key == "listen ")
            server.port = atoi(value.c_str());
        else if (key == "host")
            server.host = value;
        else if (key == "server_name")
            server.server_name = value;
        else if (key == "root")
            server.root = value;
        else if (key == "index")
            server.index = value;
        else if (key == "max_body_size")
            server.max_body_size = atoi(value.c_str());
        else if (key == "error_page")
        {
            istringstream value_iss(value);
            int code;
            string path;

            value_iss >> code >> path;
            server.error_page[code] = trim(path);
        }

        // ===================== BLOQUE LOCATION =======================
    }
}

void Config::parseLocation(ifstream &file, string& line, Location_config& location)
{
    while (getline(file, line))
    {
        line = trim(line);
        if (line.empty() || line[0] == '#')
            continue;
        if (line == "}")
            break;
        istringstream iss_location(line);
        string key, value;
        iss_location >> key >> value;
        value = trim(value);

        // ------------- IMPRIMO DIRECTIVAS LOCATION PARSEO ----------------
        cerr << "Location Parse Directives: " << endl;
        cerr << "- key: " << key << " - value: " << value << endl;

        // ------------ VOY ASIGNANDO 1A1 LAS DIRECTIVAS LOCATION ------------
        if (key == "root")
            location.root = value;
        else if (key == "index")
            location.index = value;
        else if (key == "upload_path")
            location.upload_path = value;
        else if (key == "cgi_path")
            location.cgi_path = value;
        else if (key == "redirect")
            location.redirect = value;
        else if (key == "methods")
        {
            istringstream iss_value(value);
            string method;

            while (iss_value >> method)
                location.methods.push_back(trim(method));
        }
    }
    cerr << endl;
}