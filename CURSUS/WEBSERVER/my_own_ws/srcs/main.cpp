#include <iostream>
#include "../includes/config.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"

using namespace std;

int main(int argc, char** argv)
{
    string config_path;

    if (argc <= 2)
    {
        cerr << GREEN << "Correct number of arguments" << endl;
        if (argc == 1)
            config_path = "config/config.conf";
        else
            config_path = argv[1];
        Config config_obj(config_path);

    }
    else
    {
        cerr << RED << "Wrong number of arguments! "<< endl;
    }
}