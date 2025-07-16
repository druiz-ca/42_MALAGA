#include "Server.hpp"
#include "Config.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    std::string config_file = (argc > 1) ? argv[1] : "config/default.conf";
    std::cerr << "DEBUG: Loading config file: " << config_file << std::endl;

    // Parsear el archivo de configuración
    Config config;
    try {
        config.load(config_file);
    } catch (const std::exception& e) {
        std::cerr << "ERROR: Failed to load config: " << e.what() << std::endl;
        return 1;
    }

    // Crear una sola instancia de Server
    Server* server = NULL;
    try {
        server = new Server(config);
        std::cerr << "DEBUG: Created server instance" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "ERROR: Failed to create server: " << e.what() << std::endl;
        return 1;
    }

    // Ejecutar el servidor
    try {
        server->run();
    } catch (const std::exception& e) {
        std::cerr << "ERROR: Server runtime error: " << e.what() << std::endl;
        delete server;
        return 1;
    }

    // Limpiar
    delete server;
    return 0;
}