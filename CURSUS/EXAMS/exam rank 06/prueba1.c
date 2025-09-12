#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <errno.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_MSG_LEN 1000000
#define MAX_CLIENTS 1024

typedef struct s_client
{
    int id;
    char msg[MAX_MSG_LEN];
}t_client;
t_client clientes[MAX_CLIENTS];

fd_set read_fd, write_fd, monitored_fd;
char comunicado[MAX_MSG_LEN], recv_buffer[MAX_MSG_LEN];
int max_fd = 0, current_id = 0;

void ft_error(char *msg) {
  if (msg)
    write(2, msg, strlen(msg));
  else
    write(2, "Fatal error", 11);
  write(2, "\n", 1);
  exit(1);
}

// Send message to all clients
void enviar_comunicado(int except) 
{
    printf("%s", comunicado);
  for (int fd = 0; fd <= max_fd; fd++) 
  {
    if (FD_ISSET(fd, &write_fd) && fd != except) 
    {
      if (send(fd, comunicado, strlen(comunicado), 0) == -1)
        ft_error(NULL);
    }
  }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        ft_error("Wrong");
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1)
        ft_error(NULL);
    FD_ZERO(&monitored_fd);
    FD_SET(server_fd, &monitored_fd);
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
    socklen_t len = sizeof(struct sockaddr_in);

    while(1)
    {
        read_fd = write_fd = monitored_fd;
        if(select(max_fd+1, &read_fd, &write_fd, 0, 0)==-1)
            continue;
        for(int fd = 0; fd <= max_fd; fd++)
        {   
            if (FD_ISSET(fd, &read_fd))
            {
                if(fd == server_fd)
                {
                    if((client_fd = accept(server_fd, (struct sockaddr*)&server_config, &len))==-1)
                        continue;
                    if (max_fd < client_fd)
                        max_fd = client_fd;
                    FD_SET(client_fd, &monitored_fd);
                    clientes[client_fd].id = current_id++;
                    sprintf(comunicado, "client %d\n", clientes[client_fd].id);
                    enviar_comunicado(client_fd);
                    //break;
                }else{
                    struct sockaddr_in client_config;
                    bzero(&client_config, sizeof(client_config));
                    int bytes_leidos = recv(fd, recv_buffer, sizeof(recv_buffer), 0);
                    if(bytes_leidos <= 0)
                    {
                        sprintf(comunicado, "client %d has disconected", clientes[fd].id);
                        enviar_comunicado(fd);
                        FD_CLR(fd, &monitored_fd);
                        close(fd);
                        //break;
                    }else{
                        for(int i = 0, j = strlen(clientes[fd].msg); i < bytes_leidos; i++, j++)
                        {
                            clientes[fd].msg[j] = recv_buffer[i];
                            if(clientes[fd].msg[j] == '\n')
                            {
                                clientes[fd].msg[j] = '\0';
                                sprintf(comunicado, "client %d: %s\n", clientes[fd].id, clientes[fd].msg);
                                enviar_comunicado(fd);
                                bzero(clientes[fd].msg, strlen(clientes[fd].msg));
                                j = -1;
                            }
                        }
                    }
                }
            }
        }
    }
}