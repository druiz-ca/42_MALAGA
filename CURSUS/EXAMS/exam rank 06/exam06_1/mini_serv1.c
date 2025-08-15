#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <errno.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 1024
#define MAX_MSG_SIZE 1000000

typedef struct s_client
{
	int id;
	char msg[MAX_MSG_SIZE];
}t_client;
t_client clientes[MAX_CLIENTS];

fd_set read_fd;
fd_set write_fd;
fd_set monitored_fds;

char read_buffer[MAX_MSG_SIZE];
char recv_buffer[MAX_CLIENTS];

int current_id= 0;
int max_fd = 0;

int main(int argc, char** argv)
{
	if(argc != 2)
		ft_error("ERROR");
	int socket_fd;
	if(socket(AF_INET, SOCK_STREAM, 0)!=0)
		ft_error(NULL);
	FD_ZERO(&monitored_fds);
	FD_SET(socket_fd, &monitored_fds);
	max_fd = socket_fd;

	struct sockaddr_in server_config;
	bzero(&server_config, sizeof(server_config));
	server_config.sin_port = htons(atoi(argv[1]));
	server_config.sin_family = AF_INET;
	server_config.sin_addr.s_addr = inet_addr("127");

	if(bind(socket_fd, (const struct sockaddr*)&server_config, sizeof(server_config))!= 0)
		ft_error(NULL);
	if(listen(socket_fd, 10)!= 0)
		ft_error(NULL);

	int client_fd = 0;

	while(1)
	{
		read_fd = monitored_fds;
		write_fd = monitored_fds;

		if(select(max_fd+1, &read_fd, &write_fd, NULL, NULL)!= 0)
			ft_Error(NULL);
		for (int fd = 0; fd <= max_fd; fd++)
		{
			if(FD_ISSET(fd, &read_fd))
			{
				if(fd==socket_fd)
				{
					struct sockaddr_in client_addr;
					bzero(&client_addr, sizeof(client_addr));

					if((client_fd = accept(socket_fd, (const struct sockaddr*)&client_addr, sizeof(client_addr)))<0)
						ft_error(NULL);
					if(client_fd > max_fd)
						max_fd = client_fd;
				}
			}
		}
	}
	
}