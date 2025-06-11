
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char *gnl(int fd)
{
    char *res;
    int i = 0;
    char buffer[4];
    char linea[100];
    int buffer_pos;
    int buffer_read;

    buffer_read = read(fd, buffer, 4);
    while (buffer_read > 0)
    {
        if (buffer_pos >= buffer_read)
        {
            buffer_read = read(fd, buffer, 4);
            buffer_pos = 0;
        }
        linea[i++] = buffer[buffer_pos++];
    }
    linea[--i] = '\0';
    res = linea;
    return (res);
}

int main()
{
    int fd;
    fd = open("txt.txt", O_RDONLY);
    printf("%s", gnl(fd));
}