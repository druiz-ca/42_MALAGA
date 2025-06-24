#include "../includes/config.hpp"

Config::Config(const string& filepath)
{
    cerr << filepath << endl;
    parse(filepath);
}

void Config::parse(const string& filepath)
{
    ifstream file(filepath.c_str());

    if (!file.is_open())
    {
        cerr << "Could not open file: " << filepath << endl;
    }
}