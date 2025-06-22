#include "Server.hpp"	// Include the Server class header file to define the server functionality.
#include <iostream>		// For std::cerr and std::cout to print error messages and debug information.

int main(int argc, char* argv[]) {
    std::string config_file = (argc > 1) ? argv[1] : "config/default.conf";
    try {
        Config config(config_file);
        Server server(config);
        server.start();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}