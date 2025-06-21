#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char *gnl(int fd)
{
    char linea[100];
    char *res;
    int i, j;
    i = 0;
    j = 0;
    char buffer[4];
    int buffer_size = 0;
    int buffer_pos = 0;

    buffer_size = read(fd, buffer, 4);
    while (buffer_size > 0)
    {
        if (buffer_pos >= buffer_size)
        {
            buffer_size = read(fd, buffer, 4);
            buffer_pos = 0;
        }
        linea[i++] = buffer[buffer_pos++];
    }
    i--;
    linea[i] = '\0';
    res = linea;
    return (res);
}

int main()
{
    int fd = open("txt.txt", O_RDONLY);
    printf("%s\n",gnl(fd));
}