// 8 includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <errno.h> // Para errores del sistema
//#include <netdb.h> // NO SE USA
#include <netinet/in.h> // Estructuras para sockets (SOCKADDR_IN)
#include <sys/socket.h> // socket, bind, listen, accept, send, recv
#include <sys/select.h> // para select, FD_SET, FD_ISSET, FD_ZERO
#include <arpa/inet.h>

#define MAX_MSG_SIZE 10000 // 1M
#define MAX_CLIENTS 1024

typedef struct s_client // s -> struct
{
	int	id;
	char	msg[MAX_MSG_SIZE];
}t_client; // t -> typedef
// sino uso t_client(alias) tendria que poner typedef struct siempre

t_client clients[MAX_CLIENTS];
fd_set read_set, write_set, monitored_fds;	
char send_buffer[MAX_MSG_SIZE], recv_buffer[MAX_MSG_SIZE];
int current_id = 0, maxfd = 0;

void err(char *str)
{
	if(str)
		write(2, str, strlen(str));
	else
		write(2, "Fatal error", 11);
	write(2, "\n", 1);
	exit(1);
}
// Para enviar el mensaje a todos los clientes menos al que lo envía
void	enviar_comunicado(int accepted)
{
	for (int fd = 0; fd <= maxfd; fd++)
	{	//comrueba q fd's están listos para escritura (q se les pueda 
		// enviar un mensaje)
		if (FD_ISSET(fd, &write_set) && fd != accepted)
		{
			if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
				err(NULL);
		}
	}
}

int main(int ac, char **av)
{
	// ============================ CONFIGURACIÓN =========================== //
	if (ac != 2)
		err("Wrong number of arguments\n");
	
	// ==================== SOCKET ========================= //
	int server_fd;

	// Creación del socket
		// AFINET-> dir IP en formato IPv4 (127.0.0.1)
			// address family internet
		// SOCK:STREAM -> indica socket orientado a conexión
			// con protocolo TCP (maneja control d errores)
			// Socket stream(flujo)
	server_fd = socket(AF_INET, SOCK_STREAM, 0); // 3 
	// Verificación del socket
	if (server_fd == -1)
		err(NULL);
	// Limpiar EL conjunto de fd
	FD_ZERO(&monitored_fds);
	// =====================================================
	// Agrega el sockfd del servidor al conjunto de fds (monitored_fds)
	FD_SET(server_fd, &monitored_fds);

	// ==================== FIN SOCKET ====================== //
	
	// ================== SERVERADDR & MONITORED ===================== //
	struct sockaddr_in server_config; // almacena la IP y puerto del serv.
	// limpieza de la estructura server_config
	bzero(&server_config, sizeof(server_config)); 
	bzero(&clients, sizeof(clients));
	// Establece la fam de dir. q usará el socket, la IP, el Puerto ... 
	server_config.sin_family = AF_INET; // fam. de direcc. q usará para el socket
	//server_config.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	server_config.sin_addr.s_addr = inet_addr("127.0.0.1");//USAR ESTA!!
	server_config.sin_port = htons(atoi(av[1]));  // 8080
	
	// ================== FIN SERVERADDR & MONITORED =================== //
	
	// Establece el actual sockfd como el num maximo fd
	maxfd = server_fd; // 3

	
	// Enlaza el socket a una IP y un puerto 
	if ((bind(server_fd, (const struct sockaddr *)&server_config, sizeof(server_config))) != 0)
		err(NULL);

		// convierte el socket a pasivo -> xra q pueda aceptar conexiones
		// escuchará hasta 10 clientes pendientes de accept
	if (listen(server_fd, 10) != 0)
		err(NULL);  
		
		// ==================== FIN DE LA CONFIGURACIÓN ====================== //
	int client_fd; // fd del socket del cliente para nueva conexión

	while (1)
	{
		read_set = write_set = monitored_fds;

		// Detecta 1 fds están listos (para enviar o recibir datos)
			// modifica los conjuntos para indicar qué fds están listos
			// Va aumentado el maxfd cada vez que slecciona un fd nuevo
		if (select(maxfd + 1, &read_set, &write_set, NULL, NULL) == -1)
			continue;
		for (int fd = 0; fd <= maxfd; fd++)
		{
			// Comprueba si un fd está listo para aceptar nueva conexión
			if (FD_ISSET(fd, &read_set))
			{
				// si el evento detectado x select coincide con el del servidor
				// (si fd sirve para identificar si es del servidor o no, es decir
				// fd se usa para compararlo, si es igual al socket es que lo que
				// ha sucedido es en el socket del servidor)
				// - detectada una conexión entrante!
				// este bloque solo prepara y configura la nueva conexión entrante
				if (fd == server_fd) 
				{
					// Para almacenar la info de la dir. del cliente conectado
					struct sockaddr_in cli;

					// Limpieza de la estructura
					bzero(&cli, sizeof(cli));

					// Obtengo la longitud
					socklen_t len = sizeof(cli);

					// Acepto la conexión -> devuelvo fd de cliente conectado
						// Asigna el nº de fd + bajo disponible
					client_fd = accept(server_fd, (struct sockaddr *)&cli, &len);

					// Comprobaciones
					if (client_fd < 0)
						continue; // nuevo
					
					// Actualizo maxfd
					if (client_fd > maxfd)
						maxfd = client_fd;

					// Asigno la id actual
					clients[client_fd].id = current_id;

					// Incremento la id actual
					current_id++;

					// Agrega el fd del cliente al conjunto
					FD_SET(client_fd, &monitored_fds);

					// Imprime mensaje
					sprintf(send_buffer, "server: client %d just arrived\n", clients[client_fd].id);
					
					// Notifica a todos los clientes (menos este) q alguien se ha contectado
					enviar_comunicado(client_fd);
					break; // nuevo
				}
				
				// si el fd detectado x select corresponde al del cliente
				// - el cliente conectado ya ha enviado datos al servidor
				else // Procesa los datos recibidos x el cliente
				{
					// recibe los datos enviados x el cliente (recovery)
					int bytes_recv = recv(fd, recv_buffer, MAX_MSG_SIZE, 0);
					 
					// Comprueba que el cliente siga conectado
					if (bytes_recv <= 0) // cliente desconectado
					{
						sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
						
						// Notifico a todos los clientes que se ha desconectado
						enviar_comunicado(fd);

						// Elimino el fd del cliente del conjunto
						FD_CLR(fd, &monitored_fds);

						// Cierro el fd
						close(fd);
						break; // nuevo
					}
					else // cliente conectado
					{
						// Recorre todos los bytes recibidos
						for (int i = 0, j = strlen(clients[fd].msg); i < bytes_recv; i++, j++)
						{
							// Copia byte a byte el contenido del mensaje
							clients[fd].msg[j] = recv_buffer[i];

							// Cuando llega al salto de linea
							if (clients[fd].msg[j] == '\n')
							{
								// termina la cadena copiada
								clients[fd].msg[j] = '\0';

								// Imprime el mensaje enviado
								sprintf(send_buffer, "client %d: %s\n", clients[fd].id, clients[fd].msg);
								
								// Lo notifica a todos los clientes conectados
								enviar_comunicado(fd);

								// Limpieza
								bzero(clients[fd].msg, strlen(clients[fd].msg));
														// 
								j = -1;
							}
						}
					}
				}
			}
		}
	}
}