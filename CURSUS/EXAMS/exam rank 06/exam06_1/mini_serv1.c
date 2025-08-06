#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/select.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>

#define CLIENTES_MAX 1024
#define LONGITUD_MAX_MSG 1000000

typedef struct s_client
{
	int id;
	char msg[LONGITUD_MAX_MSG];
}t_client;

t_client struct_clientes[CLIENTES_MAX];		

fd_set write_set;
fd_set read_set;
fd_set fds_monitoreados;

char buffer_read[LONGITUD_MAX_MSG];
char recv_buffer[LONGITUD_MAX_MSG];

int fd_actual = 0;
int max_fds = 0;

int main(int argc, char **argv)
{
	if (argc != 2)
		ft_err("Wrong number of arguments\n");
	
	int socket_fd = 0;
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd == -1)
		ft_error (NULL);
	FD_ZERO(&fds_monitoreados);
	FD_SET(socket_fd, &fds_monitoreados);

	struct sockaddr_in server_config;
	bzero(&server_config, sizeof(server_config));
	server_config.sin_addr.s_addr = AF_INET;
	server_config.sin_family = inet_addr("127.0.0.1");
	server_config.sin_port = htons(atoi(argv[1]));
	
	max_fds = socket_fd;

	if ((bind(socket_fd, (const struct sockaddr*))))
}