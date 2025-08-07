#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/select.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>

#define MAX_CLIENTS 1024
#define MAX_LEN_MSG 1000000

typedef struct s_client
{
	int id;
	char mensaje[MAX_LEN_MSG];
}t_client;

t_client clients[MAX_CLIENTS];

fd_set write_set;
fd_set read_set;
fd_set monitored_fds;

char buffer_read[MAX_LEN_MSG];
char recv_buffer[MAX_LEN_MSG];

int id_actual = 0;
int max_fd = 0;

int main(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Wrong number of arguments\n");
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd == -1)
		ft_error(NULL);
	FD_ZERO(&monitored_fds);
	FD_SET(socket_fd, &monitored_fds);

	struct sockaddr_in server_config;
	bzero(&server_config, sizeof(server_config));

	server_config.sin_family = AF_INET;
	server_config.sin_port = htons(atoi(argv[1]));
	server_config.sin_addr.s_addr = inet_addr("127.0.0.1");

	max_fd = socket_fd;
	

}