#include "../includes/config.hpp"

Config::Config(const string& filepath)
{
    cerr << filepath << endl;
    parse(filepath);
}

void Config::parse(const string& filepath)
{
    // c_str convierte un tipo string a tipo const char*
    // crea objeto ifstream con la ruta como parámetro pq permite controlar
    //     si se ha abierto el archivo
    ifstream file(filepath.c_str());

    if (!file.is_open())
        throw runtime_error("Could not open config file: " + filepath);
}