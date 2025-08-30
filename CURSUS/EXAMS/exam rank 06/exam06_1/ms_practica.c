#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <errno.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>

#define MAX_MSG_LEN 1000000
#define MAX_CLIENTS 1024

typedef struct s_client
{
    int id;
    char msg[MAX_MSG_LEN];
}t_client;

t_client clientes[MAX_MSG_LEN];

fd_set write_fd;
fd_set read_fd;
fd_set monitored_fds;

char comunicado[MAX_MSG_LEN];
char recv_buffer[MAX_MSG_LEN];

int current_id = 0;
int max_fd = 0;

int main(int argc, char **argv)
{
    if(argc!=2)
        ft_error("wrong");
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd ==-1)
        ft_error(NULL);
    FD_ZERO(&monitored_fds);
    FD_SET(socket_fd, &monitored_fds);
    max_fd = socket_fd;

    struct sockaddr_in server_config;
    bzero(&server_config, sizeof(server_config));
    server_config.sin_addr.s_addr = inet_addr("127");
    server_config.sin_port = htons(atoi(argv[1]));
    server_config.sin_family = AF_INET;

    if(bind(socket_fd, (const struct sockaddr*)&server_config, sizeof(server_config))==-1)
        ft_error(NULL);
    if(listen(socket_fd, 10)==-1)
        ft_error(NULL);
    int client_fd = 0;
    while(1)
    {
        read_fd = monitored_fds;
        write_fd = monitored_fds;
        if(select(max_fd+1, &read_fd, &write_fd, NULL, NULL)==-1)
            ft_error(NULL);
        for(int fd = 0; fd <= max_fd; fd++)
        {
            if(FD_ISSET(fd, &read_fd))
            {
                if(fd == socket_fd)
                {
                    struct sockaddr_in client_config;
                    bzero(&client_config, sizeof(client_config));
                    if(client_fd = accept(socket_fd, (const struct sockaddr*)&client_config, sizeof(client_config))==-1)
                        ft_error(NULL);
                    if(max_fd < client_fd)
                        max_fd = client_fd;
                    clientes[client_fd].id = current_id++;
                    FD_SET(client_fd, &monitored_fds);
                    sprintf(comunicado, "server_ client %d", clientes[client_fd].id);
                    enviar_comunicado(client_fd);
                }else{
                    int bytes_leidos = recv(fd, recv_buffer, strlen(recv_buffer), 0);
                    if(bytes_leidos <= 0)
                    {
                        sprintf(comunicado, "client %d desconect", clientes[client_fd].id);
                        enviar_comunicado(fd);
                        FD_CLR(fd, &monitored_fds);
                        close(fd);
                    }else{
                        for(int i = 0, j = strlen(clientes[client_fd].msg); i < bytes_leidos; i++, j++)
                        {
                            clientes[fd].msg[j] = recv_buffer[i];
                            if(clientes[fd].msg[j] == '\n')
                            {
                                clientes[fd].msg[j] == '\0';
                                sprintf(comunicado, "client %d: &s\n", clientes[fd].id, clientes[fd].msg);
                                enviar_comunicado(fd);
                                bzero(&clientes[fd].msg, strlen(clientes[fd].msg));
                                j = -1;
                            }
                        }
                    }
                }
            }
        }
    }

}