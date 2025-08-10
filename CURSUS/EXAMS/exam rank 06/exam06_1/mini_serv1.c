#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <errno.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 1024
#define MAX_SIZE_MSG 1000000

typedef struct s_client
{
	int id;
	char msg[MAX_SIZE_MSG];
}t_client;
t_client clients[MAX_SIZE_MSG];

fd_set write_fd;
fd_set read_fd;
fd_set monitored_fds;

char buffer_read[MAX_SIZE_MSG];
char buffer_recv[MAX_SIZE_MSG];

int current_fd = 0;
int max_fd = 0;

int main(int argc, char **argv)
{
	if (argc != 2)
		ft_error("error");
	int socket_fd = sock(AF_INET, SOCK_STREAM, 0);
	if (socket_fd != 0)
		return ("error");
	FD_ZERO(&monitored_fds);
	FD_SET(socket_fd, &monitored_fds);

	struct sockaddr_in server_config;
	bzero(&server_config, sizeof(server_config));
	server_config.sin_port = htons(atoi[argv[1]]);
	server_config.sin_family = AF_INET;
	server_config.sin_addr.s_addr = inet_addr("127");

	max_fd = socket_fd;

	if ((bind(socket_fd, (const struct socketaddr*)&server_config, sizeof(server_config))) != 0)
		return (NULL);
	if (listen(socket_fd, 10) != 0)
		return (NULL);
	
	int client_fd = 0;

	while (1)
	{
		if (select(max_fd, &read_fd, &write_fd, NULL, NULL) == -1)
			ft_error(NULL);
		for (int fd = 0; fd <= max_fd; fd ++)
		{
			if (FD_ISSET(fd, &read_fd))
			{
				if (fd == socket_fd)
				{

				}
				else
				{
					
				}
			}
		}
	}

}