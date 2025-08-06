#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/select.h>

#define LONGITUD_MAX_MENSAJE 1000000
#define CLIENTES_MAXIMOS 1024

typedef struct s_client
{
    int id;
	char msg[LONGITUD_MAX_MENSAJE];
}t_client;

t_client clientes[CLIENTES_MAXIMOS];

fd_set write_set;
fd_set read_set;
fd_set fds_monitoreados;

char send_buffer[LONGITUD_MAX_MENSAJE];
char recv_buffer[LONGITUD_MAX_MENSAJE];

int id_actual = 0;
int max_num_fds = 0;

