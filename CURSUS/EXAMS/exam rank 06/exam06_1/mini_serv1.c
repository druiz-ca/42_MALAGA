#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>

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
fd_set current_set;

char buffer_send[MAX_MSG_SIZE];
char buffer_recv[MAX_MSG_SIZE];

int current_id = 0;
int max_fd = 0;

