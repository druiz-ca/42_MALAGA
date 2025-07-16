#include <iostream>
#include "../includes/Config.hpp"
#include "../includes/Server.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

using namespace std;

int main(int argc, char** argv)
{
    string config_path;

    if (argc <= 2)
    {
        try
        {   // si no reseteas el color sigue imprimiendo en verde todo el rato!!!
            cerr << GREEN << "Correct number of arguments" << RESET << endl;
            if (argc == 1)
                config_path = "config/default.conf";
            else
                config_path = argv[1];
            Config config_obj(config_path);

            // crea objeto servidor con el 1er servidor configurado
            Server server(config_obj.getServers()[0]);
            server.run();
        }
        catch(const exception& e) {
            cerr << e.what() << endl;
            return 1;
        }        
    }
    else
    {
        cerr << RED << "Wrong number of arguments! "<< endl;
    }
}