#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    // Crear el socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Configurar el socket para reutilizar la dirección
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Configurar la dirección y el puerto
    struct sockaddr_in server_addr;
    std::memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;       // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Escuchar en todas las interfaces
    server_addr.sin_port = htons(8080);    // Puerto 8080

    // Enlazar el socket a la dirección y puerto
    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // Poner el socket en modo escucha
    listen(server_fd, 10);

    std::cout << "Server is listening on port 8080..." << std::endl;

    // Aceptar conexiones de clientes
    while (true) 
    {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);

        std::cout << "New client connected!" << std::endl;

        // Enviar una respuesta HTTP básica
        std::string response = 
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: 13\r\n"
            "\r\n"
            "Hello, world!";
        send(client_fd, response.c_str(), response.length(), 0);

        // Cerrar la conexión con el cliente
        close(client_fd);
    }

    // Cerrar el socket del servidor
    close(server_fd);
    return 0;
}