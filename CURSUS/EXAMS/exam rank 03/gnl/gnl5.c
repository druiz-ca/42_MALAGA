#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


char *gnl(int fd)
{
    int i = 0; 
    char *res;
    char buffer[400];
    char linea[1000];
    int buffer_read = 0;
    int buffer_pos = 0;


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
    linea [--i] = '\0';
    res = linea;
    return (res);
}

int main()
{
    int fd = open("txt.txt", O_RDONLY);
    printf("%s", gnl(fd));
}