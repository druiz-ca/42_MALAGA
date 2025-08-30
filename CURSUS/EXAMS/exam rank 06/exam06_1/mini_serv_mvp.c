#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 1024
#define MAX_MSG_SIZE 1000000
typedef struct s_client{
	int id;
	char msg[MAX_MSG_SIZE];
}t_client;
t_client clientes[MAX_CLIENTS];
fd_set read_fd, write_fd, monitored_fds;
char send_buffer[MAX_MSG_SIZE];
char recv_buffer[MAX_CLIENTS];
int current_id= 0;
int max_fd = 0;
int main(int argc, char** argv){
	if(argc!=2)
		ft_error("ERROR");
	int server_fd = sock(AF_INET, SOCK_STREAM, 0);
	if(server_fd != 0)
		ft_error(NULL);
	FD_ZERO(&monitored_fds);
	FD_SET(server_fd, &monitored_fds);
	max_fd = server_fd;
	struct sockaddr_in server_config;
	bzero(&server_config, sizeof(server_config));
	server_config.sin_port = htons(atoi(argv[1]));
	server_config.sin_family = AF_INET;
	server_config.sin_addr.s_addr = inet_addr("127");
	if((bind(server_fd, (const struct socketaddr*)&server_config, sizeof(server_config)))!=0)
		ft_error(NULL);
	if(listen(server_fd, 10)!= 0)
		ft_error(NULL);
	int client_fd;
	while(1){
		read_fd = monitored_fds;
		write_fd = monitored_fds;
		if(select(max_fd+1, &read_fd, &write_fd, NULL, NULL) == -1)
			ft_error(NULL);
		// va recorriendo todos los fd hasta que encuentra uno maracdo
		// para lectura (FD_ISSET)
		for(int fd = 0; fd<= max_fd; fd++)
		{
			if(FD_ISSET(fd, &read_fd)){
				if(fd == server_fd){// nueva conexion
					struct sockaddr_in client_config;
					bzero(&client_config, sizeof(client_config));
					if(client_fd = accept(server_fd, (const struct sockaddr*)&client_config, sizeof(client_config))==-1)
						ft_error(NULL);
					if(max_fd < client_fd)
						max_fd = client_fd;
					clientes[client_fd].id = current_id++;
					FD_SET(client_fd, &monitored_fds);
					// guarda en send:buffer el msg de nueva conexion
					sprintf(send_buffer, "server: client %d just arrived", clientes[client_fd].id);
					enviar_comunicado(client_fd);
				}else{ 	// receive
					int bytes_recv = recv(fd, recv_buffer, MAX_MSG_SIZE, 0);
					if (bytes_recv <= 0) {// cliente desconectado o error
						sprintf(send_buffer, "server:  client %d just left\n", clients[fd].id);
						enviar_comunicado(fd);
						FD_CLR(fd, &monitored_fds); //dejo de monitorearlo
						close(fd);// cierr el fd de ese cliente
					}else{// nuevo mensaje
						for (int i = 0, j = strlen(clientes[fd].msg); i < bytes_recv; i++, j++)
						{
							clientes[fd].msg[j] = recv_buffer[i];
							if (clientes[fd].msg[j] == '\n')
							{
								clientes[fd].msg[j] = '\0';
								sprintf(send_buffer, "client %d: %s\n", clientes[fd].id, clients[fd].msg);								send_broadcast(fd);
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