#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/select.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_CLIENTS 1024
#define MAX_MSG_LEN 1000000

typedef struct s_client
{
    int id;
    char msg[MAX_MSG_LEN];
}t_client;
t_client clientes[MAX_CLIENTS];

fd_set write_fd, read_fd, monitored_fds;
int current_id = 0, max_fd = 0;
char recv_buffer[MAX_MSG_LEN], comunicado[MAX_MSG_LEN];

void ft_error(char *str)
{
    if(str)
        write(2, str, strlen(str));
    else
        write(2, "fatal error", 11);
    write(2, "\n", 1);
    exit(1);
}

void enviar_comunicado(int client_fd)
{

}

int main(int argc, char **argv)
{
    if(argc!= 2)
        ft_error("wrong num");
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1)
        ft_error(NULL);
    FD_ZERO(&monitored_fds);
    FD_SET(server_fd, &monitored_fds);
    max_fd = server_fd;

    struct sockaddr_in server_config;
    bzero(&server_config, sizeof(server_config));
    server_config.sin_port = htons(atoi(argv[1]));
    server_config.sin_family = AF_INET;
    server_config.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(bind(server_fd, (const struct sockaddr*)&server_config, sizeof(server_config))==-1)
        ft_error(NULL);
    if(listen(server_fd, 10)==-1)
        ft_error(NULL);
    int client_fd = 0;

    while(1)
    {
        read_fd = write_fd = monitored_fds;
        if(select(max_fd+1, &read_fd, &write_fd, 0, 0)==-1)
            continue;
        for(int fd = 0; fd <= max_fd; fd++)
        {
            if(FD_ISSET(fd, &read_fd))
            {
                
            }
        }
    }
}