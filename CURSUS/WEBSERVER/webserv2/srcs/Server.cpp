#include "Server.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <errno.h>
#include <sys/time.h>
#include <cerrno>
#include <cstring>
#include <sys/types.h>
#include <sys/select.h>

Server::Server(const ServerConfig& conf) : sockfd(-1), config(conf), clients() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr    << "Error creating socket: " << std::strerror(errno) << std::endl;
        std::cerr.flush();
        return;
    }

    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        std::cerr << "Error setting socket options: " << std::strerror(errno) << std::endl;
        std::cerr.flush();
        close(sockfd);
        sockfd = -1;
        return;
    }

    if (fcntl(sockfd, F_SETFL, O_NONBLOCK) < 0) {
        std::cerr << "Error setting socket to non-blocking: " << std::strerror(errno) << std::endl;
        std::cerr.flush();
        close(sockfd);
        sockfd = -1;
        return;
    }

    struct sockaddr_in addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(config.port);

    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        std::cerr << "Error binding socket: " << std::strerror(errno) << std::endl;
        std::cerr.flush();
        close(sockfd);
        sockfd = -1;
        return;
    }

    if (listen(sockfd, 10) < 0) {
        std::cerr << "Error listening on socket: " << std::strerror(errno) << std::endl;
        std::cerr.flush();
        close(sockfd);
        sockfd = -1;
        return;
    }

    std::cerr << "DEBUG: Server initialized on port " << config.port << std::endl;
    std::cerr.flush();
}

void Server::run() {
    fd_set read_fds;
    int max_fd = sockfd;

    std::cerr << "DEBUG: Started server on port: " << config.port << "\n";
    std::cerr.flush();

    while (true) {
        FD_ZERO(&read_fds); // Limpiar read_fds
        FD_SET(sockfd, &read_fds); // Añadir socket del servidor
        max_fd = sockfd; // Resetear max_fd

        // Añadir descriptores de clientes y verificar timeout
        for (size_t i = 0; i < clients.size(); ) {
            int client_fd = clients[i].fd;
            FD_SET(client_fd, &read_fds);
            if (client_fd > max_fd) {
                max_fd = client_fd;
            }

            // Verificar timeout
            time_t now;
            time(&now);
            if (difftime(now, clients[i].last_activity) > KEEP_ALIVE_TIMEOUT) {
                std::cerr << "DEBUG: Timeout for client fd " << client_fd << "\n";
                std::cerr.flush();
                FD_CLR(client_fd, &read_fds); // Eliminar fd de read_fds
                close(client_fd); // Cerrar conexión
                clients.erase(clients.begin() + i); // Eliminar cliente
                continue; // No incrementar i
            }
            ++i;
        }

        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        int activity = select(max_fd + 1, &read_fds, NULL, NULL, &timeout);
        if (activity < 0 && errno != EINTR) {
            std::cerr << "ERROR: select() failed: " << std::strerror(errno) << "\n";
            std::cerr.flush();
            return; // Salida en caso de error grave
        }
        if (activity == 0) {
            continue; // Sin actividad
        }

        // Nueva conexión
        if (FD_ISSET(sockfd, &read_fds)) {
            int client_fd = accept(sockfd, NULL, NULL);
            if (client_fd < 0) {
                if (errno != EAGAIN && errno != EWOULDBLOCK) {
                    std::cerr << "ERROR: accept() failed: " << std::strerror(errno) << "\n";
                    std::cerr.flush();
                }
                continue;
            }

            // Configurar socket no bloqueante
            if (fcntl(client_fd, F_SETFL, O_NONBLOCK) < 0) {
                std::cerr << "ERROR: Failed to set client socket to non-blocking: " << std::strerror(errno) << "\n";
                std::cerr.flush();
                close(client_fd);
                continue;
            }

            std::cerr << "DEBUG: New connection: fd " << client_fd << "\n";
            std::cerr.flush();
            Client client = {client_fd, "", time(NULL)};
            clients.push_back(client);
        }

        // Manejar datos de clientes
        for (size_t i = 0; i < clients.size(); ) {
            int client_fd = clients[i].fd;
            if (!FD_ISSET(client_fd, &read_fds)) {
                ++i;
                continue;
            }

            char buffer[1024] = {0};
            ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);
            if (bytes_read < 0) {
                if (errno == EAGAIN || errno == EWOULDBLOCK) {
                    ++i;
                    continue;
                }
                std::cerr << "DEBUG: Error reading from fd " << client_fd << ": " << std::strerror(errno) << "\n";
                std::cerr.flush();
                FD_CLR(client_fd, &read_fds);
                close(client_fd);
                clients.erase(clients.begin() + i);
                continue;
            }
            if (bytes_read == 0) {
                std::cerr << "DEBUG: Connection closed by client: fd " << client_fd << "\n";
                std::cerr.flush();
                FD_CLR(client_fd, &read_fds);
                close(client_fd);
                clients.erase(clients.begin() + i);
                continue;
            }

            clients[i].buffer += std::string(buffer, bytes_read);
            clients[i].last_activity = time(NULL);
            std::cerr << "DEBUG: Received data on fd " << client_fd << ": " << clients[i].buffer << "\n";
            std::cerr.flush();

            bool keep_alive = true;
            while (!clients[i].buffer.empty() && keep_alive) {
                Request request;
                if (!request.parse(clients[i].buffer)) {
                    std::cerr << "DEBUG: Incomplete or invalid request for fd " << client_fd << "\n";
                    std::cerr.flush();
                    if (clients[i].buffer.length() > 1024 * 1024) { // Prevenir DoS
                        std::cerr << "DEBUG: Buffer too large, closing fd " << client_fd << "\n";
                        std::cerr.flush();
                        FD_CLR(client_fd, &read_fds);
                        close(client_fd);
                        clients.erase(clients.begin() + i);
                        keep_alive = false;
                    }
                    break;
                }

                std::cerr << "DEBUG: Parsed request successfully for fd " << client_fd << "\n";
                std::cerr.flush();
                Response response(request, config);
                response.handleRequest();
                std::string response_str = response.generate();
                ssize_t bytes_written = write(client_fd, response_str.c_str(), response_str.length());
                if (bytes_written < 0) {
                    if (errno == EAGAIN || errno == EWOULDBLOCK) {
                        break;
                    }
                    std::cerr << "DEBUG: Error writing to fd " << client_fd << ": " << std::strerror(errno) << "\n";
                    std::cerr.flush();
                    FD_CLR(client_fd, &read_fds);
                    close(client_fd);
                    clients.erase(clients.begin() + i);
                    keep_alive = false;
                    break;
                }

                std::cerr << "DEBUG: Sent response for fd " << client_fd << "\n";
                std::cerr.flush();
                keep_alive = request.isKeepAlive();
                if (!keep_alive) {
                    std::cerr << "DEBUG: Closing connection for fd " << client_fd << "\n";
                    std::cerr.flush();
                    FD_CLR(client_fd, &read_fds);
                    close(client_fd);
                    clients.erase(clients.begin() + i);
                    break;
                }
                std::cerr << "DEBUG: Keeping connection alive for fd " << client_fd << "\n";
                std::cerr.flush();
            }
            if (keep_alive) {
                ++i;
            }
        }
    }
}

Server::~Server() {
    if (sockfd >= 0) {
        close(sockfd);
    }
    for (size_t i = 0; i < clients.size(); ++i) {
        close(clients[i].fd);
    }
}