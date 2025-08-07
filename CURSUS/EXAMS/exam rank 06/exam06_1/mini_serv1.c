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
t_client clients[MAX_CLIENTS];

fd_set write_fd;
fd_set read_fd;
fd_set monitored_fds;

char buffer_read[MAX_SIZE_MSG];
char buffer_recv[MAX_SIZE_MSG];

int max_fds = 0;
int id_actual;

int main(int argc, char **argv)
{
	if (argc != 2)
		ft_error("wrong");
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd == -1)
		ft_error(NULL);
	FD_ZERO(&monitored_fds);
	FD_SET(socket_fd, &monitored_fds);
	
	struct sockaddr_in server_config;
	bzero(&server_config, sizeof(server_config));
	server_config.sin_family = AF_INET;
	server_config.sin_port = htons(atoi(argv[1]));
	server_config.sin_addr.s_addr = inet_addr("127");

	max_fds = socket_fd;

	if ((bind(&socket_fd, (const struct sockaddr*)&server_config, sizeof(server_config))) != 0)
		ft_error(NULL);
	if (listen(socket_fd, 10) != 0)
		ft_error(NULL);

}