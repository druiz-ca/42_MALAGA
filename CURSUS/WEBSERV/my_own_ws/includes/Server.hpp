#include "Config.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include <sys/socket.h>
#include <vector>
#include <string>
#include <cstdlib>

/* ===========================  CLASE SERVER =========================
    * Encargada de crear y gestionar un servidor web. Escucha conexiones de cliente
    y responde a sus peticiones.

    - Lee la conf de ServerConfig
    - Crea el socket (puerto) del servidor (abre el puerto para escuchar)
    - Cuando un cliente se conecta lo añade a una lista de clientes
    - Gestiona varios clientes a la vez (con select) 
        - Permite conexiones persistentes
    - Recibe y envía datos
    - Limpia recursos
        - Cuando termina cierra los sockets y libera la memoria
=====================================================================*/
class Server {
    public:
        Server(const Server_config& server_conf);
        ~Server();
        void run();

    private:
        // tiempo de espera (seg) para conexiones persistentes
        static const int KEEP_ALIVE_TIMEOUT = 30;

        // Estructura cliente
        struct Client
        {
            int fd;
            string buffer;
            time_t last_activity;
        };
        int socket_fd;
        Server_config server_config;
        vector<Client> clients;
    
};