#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <errno.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#define MAX_CLIENTS 1024
#define MAX_MSG_SIZE 1000000

typedef struct s_client
{
    int id;
    char msg[MAX_MSG_SIZE];
}t_client;

t_client clients[MAX_CLIENTS];

fd_set read_set;
fd_set write_set;
fd_set monitored_fds;

char buffer_read[MAX_MSG_SIZE];
char buffer_recv[MAX_MSG_SIZE];

int max_fd = 0;
int current_id = 0;

int main(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Wrong number of arguments\n");
	int socket_fd = 0;
	if (socket_fd = socket(AF_INET, SOCK_STREAM, 0) == -1)
		ft_error("Wrong number of arguments\n");
	FD_ZERO(&monitored_fds);
	FD_SET(socket_fd, &monitored_fds);
		
	struct sockaddr_in server_config;
	bzero(&server_config, sizeof(server_config));
	server_config.sin_family = AF_INET;
	server_config.sin_addr.s_addr = ("127.0.0.1");
	server_config.sin_port = htonl(argv[1]);

	max_fd = socket_fd;

	if ((bind(socket_fd, (const struct sockaddr *)&server_config, sizeof(server_config))) != 0)
		ft_error(NULL);
	if (listen(socket_fd, 10) != 0)
		ft_error(NULL);

	int fd_client;

	while (1)
	{
		
	}

}