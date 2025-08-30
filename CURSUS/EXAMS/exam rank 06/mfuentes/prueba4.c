#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 1024
#define MAX_MSG_LEN 1000000

typedef struct s_client
{
    int id;
    char msg[MAX_MSG_LEN];
}t_client;
t_client clientes[MAX_CLIENTS];

fd_set read_fd, write_fd, monitored_fd;
char comunicado[MAX_MSG_LEN], recv_buffer[MAX_MSG_LEN];
int max_fd = 0, current_id = 0;

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
    for(int fd = 0; fd <= max_fd; fd++)
    {
        if(FD_ISSET(fd, &write_fd) && fd != client_fd)
        {
            if(send(fd, comunicado, strlen(comunicado), 0)==-1)
                ft_error(NULL);
        }
    }
}

int main(int argc, char **argv)
{
    if(argc!= 2)
        ft_error("wrong number");
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1)
        ft_error(NULL);
    FD_ZERO(&monitored_fd);
    FD_SET(server_fd, &monitored_fd);
    max_fd = server_fd;

    struct sockaddr_in server_config;
    bzero(server_config, sieof(server_config));
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
        read_fd = write_fd = monitored_fd;
        if(select(server_fd, &read_fd, &write_fd, 0, 0) == -1)
            continue;
        for(int fd = 0; fd <= max_fd; fd++)
        {
            if(FD_ISSET(fd, &read_fd))
            {
                if(fd == server_fd)
                {
                    struct sockaddr_in client_config;
                    bzero(&client_config, sizeof(client_config));
                    client_config.sin_port = htons(atoi(argv[1]));
                    client_config.sin_family = AF_INET;
                    client_config.sin_addr.s_addr = inet_addr("127.0.0.1");
                    socklen_t len = sizeof(struct sockaddr_in);
                    if((client_fd=accept(server_fd, (struct sockaddr*)&server_config, &len))==-1)
                        ft_error(NULL);
                    if (max_fd < client_fd)
                        max_fd = client_fd;
                    clientes[client_fd].id = current_id++;
                    FD_SET(client_fd, &monitored_fd);
                    sprintf(comunicado, "client %d has connected\n", clientes[client_fd].id);
                    enviar_comunicado(client_fd);
                }else{

                }
            }
        }
    }
}