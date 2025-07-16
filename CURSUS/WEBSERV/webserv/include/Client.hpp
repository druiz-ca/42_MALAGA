#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <ctime>
#include <string>

struct Client {
    int port;
    std::string buffer; // Búfer de solicitud
    std::string response; // Búfer de respuesta pendiente
    Client(int p) : port(p) {}
};

class Client {
public:
    Client() : last_activity(std::time(NULL)) {}
    bool isTimedOut() const {
        return (std::time(NULL) - last_activity) > 30; // Timeout de 30 segundos
    }
    void updateLastActivity() {
        last_activity = std::time(NULL);
    }
private:
    std::time_t last_activity;
};

#endif