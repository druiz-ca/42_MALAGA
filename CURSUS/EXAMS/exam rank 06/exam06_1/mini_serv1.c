#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include <errno.h>
#include <netdb.h>
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

int main(int argc, char **argv)
{
    
}