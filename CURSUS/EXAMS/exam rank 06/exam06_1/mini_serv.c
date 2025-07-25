#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

#define MAX_MSG_SIZE 1000000
#define MAX_CLIENTS 1024

typedef struct s_client
{
	int	id;
	char	msg[MAX_MSG_SIZE];
}t_client;

t_client clients[MAX_CLIENTS];

int current_id = 0;
int maxfd = 0;

fd_set read_set;
fd_set write_set;
fd_set current;

char	send_buffer[MAX_MSG_SIZE];
char	recv_buffer[MAX_MSG_SIZE];

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

	// Establece el sockfd del servidor al conjunto de fds (current)
	FD_SET(sockfd, &current);
	
	// Establece IP, PORT 
	servaddr.sin_family = AF_INET; // fam. de direcc. q usará para el socket
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));  // 8080
	
	// Establece el actual sockfd como el maximo fd
	maxfd = sockfd;

	// Asocia el socket a una IP y un puerto (bind : enlazar)
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		err(NULL);

	// convierte el socket a pasivo -> xra q pueda aceptar conexiones
	// escuchará hasta 10 clientes pendientes de accept
	if (listen(sockfd, 10) != 0)
		err(NULL);

	while (1)
	{
		read_set = current;
		write_set = current;
		if (select(maxfd + 1, &read_set, &write_set, NULL, NULL) == -1)
			err(NULL);
		for (int fd = 0; fd <= maxfd; fd++)
		{
			if (FD_ISSET(fd, &read_set))
			{
				if (fd == sockfd) // si el fd es del servidor
				{
					struct sockaddr_in cli;
					bzero(&cli, sizeof(cli));
					socklen_t len = sizeof(cli);
					client_fd = accept(sockfd, (struct sockaddr *)&cli, &len);
					if (client_fd < 0)
						err(NULL);
					if (client_fd > maxfd)
						maxfd = client_fd;
					clients[client_fd].id = current_id;
					current_id++;
					FD_SET(client_fd, &current);
					sprintf(send_buffer, "server: client %d just arrived\n", clients[client_fd].id);
					send_broadcast(client_fd);
				}
				else // si el fd es del cliente
				{
					int ret = recv(fd, recv_buffer, MAX_MSG_SIZE, 0);
					if (ret <= 0)
					{
						sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
						send_broadcast(fd);
						FD_CLR(fd, &current);
						close(fd);
					}
					else
					{
						for (int i = 0, j = strlen(clients[fd].msg); i < ret; i++, j++)
						{
							clients[fd].msg[j] = recv_buffer[i];
							if (clients[fd].msg[j] == '\n')
							{
								clients[fd].msg[j] = '\0';
								sprintf(send_buffer, "client %d: %s\n", clients[fd].id, clients[fd].msg);
								send_broadcast(fd);
								bzero(clients[fd].msg, strlen(clients[fd].msg));
								j = -1;
							}
						}
					}
				}
			}
		
		}
	}
	
}