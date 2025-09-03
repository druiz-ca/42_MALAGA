#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/select.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define MAX_CLIENTS 1024
#define MAX_MSG_LEN 1000000

typedef struct s_client
{
    int id;
    char msg[MAX_MSG_LEN];
}t_client;
t_client clientes[MAX_CLIENTS];

fd_set read_fd, write_fd, monitored_fds;
char comunicado[MAX_MSG_LEN], recv_buffer[MAX_MSG_LEN];
int max_fd = 0, current_id = 0;

void ft_error(char *str)
{
    if (str)
        write(2, str, strlen(str));
    else
        write(2, "fatal error", 11);
    write(2, "\n", 1);
    exit(1);
}

void enviar_comunicado(int client_fd)
{
    printf("%s", comunicado);
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
    if(argc!=2)
        ft_error("wrong");
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1)
        ft_error(NULL);
    FD_ZERO(&monitored_fds);
    FD_SET(server_fd, &monitored_fds);
    max_fd = server_fd;

    struct sockaddr_in server_config;
    bzero(&server_config, sizeof(server_config));
    server_config.sin_port = htons(atoi(argv[1]));
    server_config.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_config.sin_family = AF_INET;

    if(bind(server_fd, (const struct sockaddr*)&server_config, sizeof(server_config))==-1)
        ft_error(NULL);
    if(listen(server_fd, 10) == -1)
        ft_error(NULL);

    int client_fd = 0;

    while(1)
    {
        read_fd = write_fd = monitored_fds;
        if(select(max_fd + 1, &read_fd, &write_fd, 0, 0)== -1)
            continue;
        for(int fd = 0; fd <= max_fd; fd++)
        {
            if(FD_ISSET(fd, &read_fd))
            {
                if (fd == server_fd)
                {
                    struct sockaddr_in client_config;
                    bzero(&client_config, sizeof(client_config));
                    socklen_t len = sizeof(struct sockaddr_in);                     // LEN!!!
                    if((client_fd = accept(server_fd, (struct sockaddr*)&client_config, &len))==-1)
                        continue;
                    if(max_fd < client_fd)
                        max_fd = client_fd;
                    clientes[client_fd].id = current_id++;
                    FD_SET(client_fd, &monitored_fds);
                    sprintf(comunicado, "client %d has connected\n", clientes[client_fd].id);
                    enviar_comunicado(client_fd);
                }else{                                                      // el 0!!
                    int bytes_leidos = recv(fd, recv_buffer, sizeof(recv_buffer), 0);
                    if(bytes_leidos <= 0)
                    {
                        sprintf(comunicado, "client %d has desconnected\n", clientes[client_fd].id);
                        enviar_comunicado(fd);
                        FD_CLR(fd, &monitored_fds);
                        close(fd);
                    }else{
                        for(int i = 0, j = strlen(clientes[fd].msg); i < bytes_leidos; i++, j++)
                        {
                            clientes[fd].msg[j] = recv_buffer[i];
                            if(clientes[fd].msg[j] == '\n')
                            {// TODO ESTO VA CON FD!!!!!
                                clientes[fd].msg[j] = '\0';
                                sprintf(comunicado, "client %d say %s\n", clientes[fd].id, clientes[fd].msg);
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