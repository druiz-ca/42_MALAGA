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

#define MAX_MSG_SIZE 1000000 // 1M
#define MAX_CLIENTS 1024

typedef struct s_client
{
	int	id;
	char	msg[MAX_MSG_SIZE];
}t_client;

t_client clients[MAX_CLIENTS];

fd_set read_set;
fd_set write_set;
fd_set current;

char send_buffer[MAX_MSG_SIZE];
char recv_buffer[MAX_MSG_SIZE];

int current_id = 0;
int maxfd = 0;

void putstr(int fd, char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void err(char *msg)
{
	if (!msg)
		putstr(2, "Fatal error\n");
	else
		putstr(2, msg);
	exit(1);
}

void	send_broadcast(int accepted)
{
	for (int fd = 0; fd <= maxfd; fd++)
	{
		if (FD_ISSET(fd, &write_set) && fd != accepted)
			if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
				err(NULL);
	}
}

int main(int ac, char **av)
{
	// ============================ CONFIGURACIÓN =========================== //
	if (ac != 2)
		err("Wrong number of arguments\n");



	int sockfd;
	int client_fd; // fd del socket del cliente para nueva conexión
	struct sockaddr_in servaddr; // almacena la IP y puerto del serv.

	// Creación del socket
		// AFINET-> dir IP en formato IPv4 (127.0.0.1)
		// SOCK:STREAM -> indica socket orientado a conexión
						// con protocolo TCP (maneja control d errores)
	sockfd = socket(AF_INET, SOCK_STREAM, 0); // 3 

	// Verificación del socket
	if (sockfd == -1)
		err(NULL);

	// limpieza de la estructura servaddr
	bzero(&servaddr, sizeof(servaddr)); 

	// Limpiar conjunto de fd
	FD_ZERO(&current);

	// Agrega el sockfd del servidor al conjunto de fds (current)
	FD_SET(sockfd, &current);
	
	// Establece la fam de dir. q usará el socket, la IP, el Puerto ... 
	servaddr.sin_family = AF_INET; // fam. de direcc. q usará para el socket
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	//servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); <-- USAR ESTA!!
	servaddr.sin_port = htons(atoi(av[1]));  // 8080
	
	// Establece el actual sockfd como el num maximo fd
	maxfd = sockfd; // 3

	// Enlaza el socket a una IP y un puerto 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		err(NULL);

	// convierte el socket a pasivo -> xra q pueda aceptar conexiones
	// escuchará hasta 10 clientes pendientes de accept
	if (listen(sockfd, 10) != 0)
		err(NULL);

	// ==================== FIN DE LA CONFIGURACIÓN ====================== //

	while (1)
	{
		read_set = current;
		write_set = current;

		// Detecta 1 fds están listos (para enviar o recibir datos)
			// modifica los conjuntos para indicar qué fds están listos
			// Va aumentado el maxfd cada vez que slecciona un fd nuevo
		if (select(maxfd + 1, &read_set, &write_set, NULL, NULL) == -1)
			err(NULL);
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
				if (fd == sockfd) 
				{
					// Para almacenar la info de la dir. del cliente conectado
					struct sockaddr_in cli;

					// Limpieza de la estructura
					bzero(&cli, sizeof(cli));

					// Obtengo la longitud
					socklen_t len = sizeof(cli);

					// Acepto la conexión -> devuelvo fd de cliente conectado
						// Asigna el nº de fd + bajo disponible
					client_fd = accept(sockfd, (struct sockaddr *)&cli, &len);

					// Comprobaciones
					if (client_fd < 0)
						err(NULL);
					
					// Actualizo maxfd
					if (client_fd > maxfd)
						maxfd = client_fd;

					// Asigno la id actual
					clients[client_fd].id = current_id;

					// Incremento la id actual
					current_id++;

					// Agrega el fd del cliente al conjunto
					FD_SET(client_fd, &current);

					// Imprime mensaje
					sprintf(send_buffer, "server: client %d just arrived\n", clients[client_fd].id);
					
					// Notifica a todos los clientes (menos este) q alguien se ha contectado
					send_broadcast(client_fd);
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
						send_broadcast(fd);

						// Elimino el fd del cliente del conjunto
						FD_CLR(fd, &current);

						// Cierro el fd
						close(fd);
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
								send_broadcast(fd);

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