#include "Server.hpp"
#include <sys/socket.h> // para crear y manipular sockets
#include <netinet/in.h> // para trabajar con direcciones de red
#include <unistd.h> // close(), read(), write()
#include <fcntl.h> // para controlar fds : fcntl()
#include <iostream> // cout, cerr
#include <errno.h> // Define la var global errno y los códigos de error del sistema
#include <cerrno> // para usar errno
#include <sys/time.h> // 
#include <cstring> // Para manipular cadenas
#include <sys/types.h> // para size_t
#include <sys/select.h> // Para fucniones y madros de fds (FD_ZERO, FD_SET, select)


Server::Server(const ServerConfig& conf) 
{ 
    sockfd = -1;          // Inicializa sockfd en -1
    config = conf;        // Asigna conf a config
    clients.clear();      // Limpia el vector de clientes (opcional, ya que se inicializa vacío)    
    // CREACION DEL SOCKET (enchufe)
    //  - crea como un "enchufe por donde el servidor podrá comunicarse con los cliente"
    //  - AF_NET : el socker usará direcciones  IPv4
    //  - SOCK_STREAM : sockert de tipo stream (conexión TCP)
    //  - 0 : define protocolo por defecto (TCP)
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // SI DA ERROR AL CREAR EL SOCKET
    if (sockfd < 0) {
        std::cerr    << "Error creating socket: " << std::strerror(errno) << std::endl;
        std::cerr.flush();
        return;
    }

    int opt = 1;

    // COMPRUEBA SI SE HA PODIDO ESTABLECER SO_REUSEADDR
    //  - sirve para evitar errores por reutilizar el puerto al reiniciar servidor
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) 
    {
        std::cerr << "Error setting socket options: " << std::strerror(errno) << std::endl;
        std::cerr.flush();
        close(sockfd);
        sockfd = -1;
        return;
    }

    // COMPRUEBA SI HA PODIDO CONFIGURAR EL SOCKET COMO NO BLOQUEANTE
    //  - evita que el progrma se quede esperando indefinidadmente si no hay
    //  enteradas o salidas de datos, sino que el programa puede antender otros clientes
    if (fcntl(sockfd, F_SETFL, O_NONBLOCK) < 0) {
        std::cerr << "Error setting socket to non-blocking: " << std::strerror(errno) << std::endl;
        std::cerr.flush();
        close(sockfd);
        sockfd = -1;
        return;
    }

    // CREA UNA ESTRUCTURA DE TIPO SOCKADDR_IN
    //  - Para almacenar la info de dirección y puerto de los servidores que
    //  va a escuchar
    struct sockaddr_in addr;

    // rellena toda la estructura de 0
    std::memset(&addr, 0, sizeof(addr));
    
    // CONFIGURACIÓN DE LA ESTRUCTURA ADDR (prepara la dirección y el puerto)
    //  - se necesita hacer esto antes de llamar a bind ya que éste usará el addr
    addr.sin_family = AF_INET; // IPv4
    
    // para escuchar en todas las interfaces
    //Esto incluye:
        //localhost (127.0.0.1), que es la dirección de loopback para la máquina local.
        //La dirección IP pública de la máquina (si tiene una).
        //Cualquier otra dirección IP configurada en la máquina.
    addr.sin_addr.s_addr = INADDR_ANY; 
    addr.sin_port = htons(config.port); // asigna el puerto donde escuchará

    // ENLAZA EL SOCKET A UNA DIR IP Y PUERTO CONCRETO
    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
    {
        std::cerr << "Error binding socket: " << std::strerror(errno) << std::endl;
        std::cerr.flush();
        close(sockfd);
        sockfd = -1;
        return;
    }

    // COMPRUEBA SI EL SOCKET PUEDE PONERSE EN MODO ESCUCHA
    //  - el 10 es el tamañode la cola de espera (cuantos clientes pueden esperar)
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

/* Es el "motor" del servidor:  
    - Acepta nuevas conexiones,
    - Atiende a varios clientes a la vez,
    - Lee y responde a las peticiones HTTP,
    - Cierra conexiones inactivas o problemáticas,
    - Y mantiene el servidor funcionando de forma eficiente y continua. */
void Server::run()
{
    fd_set read_fds;
    int max_fd = sockfd;

    std::cerr << "DEBUG: Started server on port: " << config.port << "\n";
    std::cerr.flush();

    // todo se desarrolla en un bucle infinito
    while (true) 
    {
        FD_ZERO(&read_fds); // Limpiar read_fds
        FD_SET(sockfd, &read_fds); // Añadir socket del servidor a la lista read_fds
        max_fd = sockfd; // Resetear max_fd (controla un max de conexiones)

        /* GESTIONA TODOS LOS CLIENTES CONECTADOS AL SERVIDOR ANTES DE SEGUIR
            - se asegura que ningun cliente se queda demasiado tiempo inactivo-
            - prepara todo para poder leer datos de los clientes
            - si un cliente está inactivo mucho tiempo lo desconecta */
        for (size_t i = 0; i < clients.size(); ) 
        {
            int client_fd = clients[i].fd; // extrae el fd del cliente
            
            // añande el fd del cliente al conjunto read_fds para vigilar si tiene datos para leer
                // Almacena todos los fd de clientes conectados y el fd del socket servidor
            FD_SET(client_fd, &read_fds); 
            
            // si el fd es mayor al actual lo actualiza para saber el fd más alto que tiene que vigilar
            if (client_fd > max_fd)
                max_fd = client_fd;

            // Verificar timeout
            time_t now;
            time(&now); // asigna tiempo actual

            // Calcula la dif entre hora actual y la última actividad del cliente
                // Comprueba si lleva más tiempo esperando del máximo
            if (difftime(now, clients[i].last_activity) > KEEP_ALIVE_TIMEOUT) 
            {
                std::cerr << "DEBUG: Timeout for client fd " << client_fd << "\n";
                std::cerr.flush();
                FD_CLR(client_fd, &read_fds); // Eliminar fd de read_fds
                close(client_fd); // Cerrar conexión
                clients.erase(clients.begin() + i); // Eliminar cliente
                
                // Salta el resto de código (No incrementa i)
                    // (al borrarlo, el resto de clientes suben una posición x eso en la misma pos de
                    // i ahora está el siguiente cliente )
                continue; 
            }
            ++i;
        }

        struct timeval timeout;
        timeout.tv_sec = 1;// tiempo de espera de 1 segundo
        timeout.tv_usec = 0;

        //select espera a que haya actividad en algún fd en reads_fds o que pase el tiempo (timeout)
            // devuelve el nº de fds listos si hay actividad
            // si el cliente hace (ej: localhost:8080) solo se ha conectado, pero no ha solicitado nada
            // x lo que no se considera que haya actividad
        int activity = select(max_fd + 1, &read_fds, NULL, NULL, &timeout);

        // Comprueba errores (activity = -1)
        if (activity < 0 && errno != EINTR)
        {
            std::cerr << "ERROR: select() failed: " << std::strerror(errno) << "\n";
            std::cerr.flush();
            return; // Salida en caso de error grave
        }
        if (activity == 0)
            continue; // Sin actividad

        // Comprueba si el socket del servidor tiene actividad (nueva conexión entrante)
        if (FD_ISSET(sockfd, &read_fds)) 
        {
            // Acepta la conexión y contiene un fd
            int client_fd = accept(sockfd, NULL, NULL);

            // Comprueba errores en el fd
            if (client_fd < 0) 
            {
                if (errno != EAGAIN && errno != EWOULDBLOCK) 
                {
                    std::cerr << "ERROR: accept() failed: " << std::strerror(errno) << "\n";
                    std::cerr.flush();
                }
                continue;
            }

            // Configurar socket no bloqueante
            if (fcntl(client_fd, F_SETFL, O_NONBLOCK) < 0) 
            {
                std::cerr << "ERROR: Failed to set client socket to non-blocking: " << std::strerror(errno) << "\n";
                std::cerr.flush();
                close(client_fd);
                continue;
            }

            std::cerr << "DEBUG: New connection: fd " << client_fd << "\n";
            std::cerr.flush();

            // Crea estructura para el nuevo cliente con:
                // fd
                // buffer vacío
                // tiempo de última actividad
            Client client = {client_fd, "", time(NULL)};

            // Añade el cliente a la lista de clientes conectados
            clients.push_back(client) ;
        }

        // Lee, procesa y responda a las peticiones de los clientes contectados
            // elimina clientes que se desconecten, tengan errores o no cumplan las reglas
        for (size_t i = 0; i < clients.size(); )  //VOY X AQUI EN EXCALIDRAW
        {
            // extrae fd del cliente
            int client_fd = clients[i].fd;

            // Comprueba si hay datos para leer del cliente 
            if (!FD_ISSET(client_fd, &read_fds)) 
            {
                ++i;
                continue;
            }

            // Declara buffer de hasta 1024 bytes para leer del cliente
            char buffer[1024] = {0};

            // Lee hasta 1024 bytes y devuelve cantidad de bytes leída
            ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);
            
            // Si error
            if (bytes_read < 0) 
            {
                if (errno == EAGAIN || errno == EWOULDBLOCK) 
                {
                    ++i;
                    continue;
                }
                std::cerr << "DEBUG: Error reading from fd " << client_fd << ": " << std::strerror(errno) << "\n";
                std::cerr.flush();

                // elimina el cliente
                FD_CLR(client_fd, &read_fds);
                close(client_fd);
                clients.erase(clients.begin() + i);
                continue;
            }

            // Si no ha leído nada
            if (bytes_read == 0) 
            {
                std::cerr << "DEBUG: Connection closed by client: fd " << client_fd << "\n";
                std::cerr.flush();

                FD_CLR(client_fd, &read_fds);
                close(client_fd);
                clients.erase(clients.begin() + i);
                continue;
            }

             // si ha leído entonces:
            
            // Añade los datos del buffer leído al buffer de clientes
            clients[i].buffer += std::string(buffer, bytes_read);

            // Actualiza la hora de la última actividad de ese cliente
            clients[i].last_activity = time(NULL);


            std::cerr << "DEBUG: Received data on fd " << client_fd << ": " << clients[i].buffer << "\n";
            std::cerr.flush();

            bool keep_alive = true;

            // el servidor va a procesar las peticiones del cliente mientras que:
                // - haya datos en el buffer del cliente
                // - y la conexión siga activa
            while (!clients[i].buffer.empty() && keep_alive) 
            {
                // Crea objeto request:
                    // - Almacena y maneja la petición HTTP
                Request request;

                // Parsea el buffer del cliente buscando petición Http
                if (!request.parse(clients[i].buffer)) 
                {
                    std::cerr << "DEBUG: Incomplete or invalid request for fd " << client_fd << "\n";
                    std::cerr.flush();

                    // Si el buffer es mayor a 1MB  cierra el cliente
                        // para Prevenir DoS (cliente malicioso) que quiera
                        // agotar la memoria del servidor con datos muy grandes
                    if (clients[i].buffer.length() > 1024 * 1024) 
                    { 
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

                // Crea objeto con:
                    // - la petición HTTP parseada
                    // - la configuración del servidor
                Response response(request, config);

                // Procesa la petición:
                    // - Prepara la respuesta
                    // - Decide que respuesta dar
                response.handleRequest();

                // Construye la respuesta HTTP completa en texto
                    // Asigna el texto a response_str
                std::string response_str = response.generate();

                // Envía la respuesta al fd del cliente (LO MUESTRA EN PANTALLA)
                    // Devuelve la cantidad de bytes escritos
                ssize_t bytes_written = write(client_fd, response_str.c_str(), response_str.length());
                
                // si no ha escrito ningún byte
                if (bytes_written < 0) 
                {
                    if (errno == EAGAIN || errno == EWOULDBLOCK) 
                        break;
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

                // Comprueba si la petición del cliente tiene que seguir activa
                keep_alive = request.isKeepAlive();

                // Si no tiene seguir activa: 
                if (!keep_alive) 
                {
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
            // Si tiene que seguir activa aumenta i (siguiente cliente)
            if (keep_alive)
                ++i;
        }
    }
}

Server::~Server() 
{
    // Si el fd del socket es válido lo cierra
    if (sockfd >= 0)
        close(sockfd);

    // Cierra el fd de cada cliente conectado
    for (size_t i = 0; i < clients.size(); ++i)
        close(clients[i].fd);
}