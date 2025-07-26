#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>

#define MAX_MSG_SIZE 1000000
#define MAX_CLIENTS 1024

typedef struct s_client
{
    int id;
    char msg[MAX_MSG_SIZE];
}t_client;

t_client clients[MAX_CLIENTS];

fd_set read_set;
fd_set write_set;
fd_set monitored_fds;

char buffer_send[MAX_MSG_SIZE];
char buffer_recv[MAX_MSG_SIZE];

int current_id = 0;
int max_fd = 0;

int main(int argc, char **argv)
{
    if (argc != 2)
        err ("Wrong number of arguments\n");

    int socket_fd;
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
        err(NULL);
        
    struct sockaddr_in server_addres;
    bzero(&server_addres, sizeof(server_addres));
    
    FD_ZERO(&monitored_fds);
    FD_SET(socket_fd, &monitored_fds);
    
    server_addres.sin_family


    int client_fd;
    
}