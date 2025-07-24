#include "Server.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <config_file>" << std::endl;
        return 1;
    }

    try {
        // PARSEO Y CONFIGURACIÓN DEL SERVIDOR
        Config config(argv[1]); // argv[1] -> archivo de configuración

        // COMPROBAR QUE HAY UN SERVIDOR CONFIGURADO
        if (config.getServers().empty()) {
            std::cerr << "Error: No server configurations found" << std::endl;
            return 1;
        }

        // CARGA EL SERVIDOR CONFIGURADO
            // aunque permite + de 1 servidor, se delimita a solo el 1º
        Server server(config.getServers()[0]);

        // ARRANCA EL SERVIDOR 
        server.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}