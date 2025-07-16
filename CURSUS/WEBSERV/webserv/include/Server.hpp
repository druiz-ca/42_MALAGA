#ifndef SERVER_HPP
#define SERVER_HPP

#include "Config.hpp"
#include "Request.hpp"
#include <map>
#include <string>
#include <vector>

class Request;
class Response;

class Client {
public:
    std::string buffer; // Almacena los datos recibidos del cliente
    int port; // Puerto asociado con el cliente
    size_t server_index; // Índice del ServerConfig en config.servers
    std::string response; // Almacena la respuesta pendiente para enviar
    Request* request; // Puntero al objeto Request para manejo incremental
    size_t bytes_sent; // Bytes enviados de la respuesta (para envío incremental)
    Client(int p, size_t idx) : buffer(""), port(p), server_index(idx), response(""), request(NULL), bytes_sent(0) {}
    ~Client() { if (request) delete request; }
};

class Server {
private:
    std::vector<int> server_fds; // Vector de descriptores de sockets para múltiples puertos
    std::map<int, std::vector<size_t> > port_to_server_indices; // Mapea puerto a índices de ServerConfig
    const Config& config; // Referencia a la configuración completa
    std::map<int, Client> clients;

public:
    Server(const Config& config);
    ~Server();
    void run();
    bool isRequestComplete(const Client& client) const; // Added declaration
    const std::vector<int>& getServerFds() const { return server_fds; }
};

#endif