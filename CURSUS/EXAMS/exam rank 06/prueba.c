#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <netinet/in.h>

typedef struct s_client
{
	int id;
	char msg[1000];
}t_client;
t_client clientes[1000];

fd_set read_fd, write_fd, monitored_fds;
char comunicado[1000], recv_buffer[1000];
int max_fd = 0, current_id = 0;


void ft_error(char *str)
{
	if(str)
		write(2, str, strlen(str));
	else
		write(2, "fatal", 5);
	write(2, "\n", 1);
	exit(1);
}

void enviar_comunicado(int client_fd)
{
	printf("%s", comunicado);
	for(int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &write_fd) && client_fd != fd)
		{
			if(send(fd, comunicado, strlen(comunicado), 0) == -1)
				ft_error(NULL);
		}
	}
}


int main(int argc, char **argv)
{
	if(argc != 2)
		ft_error("wring");
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd == -1)
		ft_error(NULL);
	FD_ZERO(&monitored_fds);
	FD_SET(socket_fd, &monitored_fds);
	max_fd = socket_fd;

	struct sockaddr_in server_config;
	bzero(&server_config, sizeof(server_config));
	server_config.sin_addr.s_addr = htonl(2130706433);
	server_config.sin_port = htons(atoi(argv[1]));
	server_config.sin_family = AF_INET;

	if(bind(socket_fd, (const struct sockaddr*)&server_config, sizeof(server_config)) ==-1)
		ft_error(NULL);
	if(listen(socket_fd, 10) == -1)
		ft_error(NULL);
	int client_fd = 0;

	while(1)
	{
		read_fd = write_fd = monitored_fds;
		if((select(max_fd + 1, &read_fd, &write_fd, 0, 0)) == -1)
			continue;
		for(int fd = 0; fd <= max_fd; fd++)
		{
			if(FD_ISSET(fd, &read_fd))
			{
				if(fd == socket_fd)
				{
					struct sockaddr_in client_config;
					bzero(&client_config, sizeof(client_config));
					socklen_t len = sizeof(struct sockaddr_in);
					if((client_fd = accept(socket_fd, (struct sockaddr*)&client_config, &len)) == -1)
						continue;
					if(max_fd < client_fd)
						max_fd = client_fd;
					clientes[client_fd].id = current_id++;
					sprintf(comunicado, "client %d connec\n", clientes[client_fd].id);
					enviar_comunicado(client_fd);
					FD_SET(client_fd, &monitored_fds);
				}else{
					int bytes_leidos = recv(fd, recv_buffer, sizeof(recv_buffer), 0);
					if(bytes_leidos <= 0)
					{
						sprintf(comunicado, "client %d desc\n", clientes[fd].id);
						enviar_comunicado(fd);
						FD_CLR(fd, &monitored_fds);
						close(fd);
					}else{
						for(int i = 0, j = strlen(clientes[fd].msg); i < bytes_leidos; i++, j++)
						{
							clientes[fd].msg[j] = recv_buffer[i];
							if(clientes[fd].msg[j] == '\n')
							{
								clientes[fd].msg[j] = '\n';
								sprintf(comunicado, "client %d, say %s\n", clientes[fd].id, clientes[fd].msg);
								enviar_comunicado(fd);
								bzero(clientes[fd].msg, strlen(clientes[fd].msg));
								j = -1;
							}
						}						
					}
				}
			}
		}
	}

}
