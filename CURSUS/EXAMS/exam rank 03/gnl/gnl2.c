#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char*    get_next_line(int fd)
{
    char linea[100];
    char buffer[4];
    int buffer_read = 0;
    int buffer_pos = 0;
    char *res;
    int i, j;
    i = 0;
    j = 0;

    buffer_read = read(fd, buffer, 4);
    while (buffer_read > 0)
    {
        if (buffer_pos >= buffer_read)
        {
            buffer_read = read(fd, buffer, 4);
            if (buffer_read <= 0)
                break;
            buffer_pos = 0;
        }   
        linea[i++] = buffer[buffer_pos++]; 
    }
    linea[i] = '\0';
    res = linea;
    return (res);
}
/* buffer_read = read
while (buffer_read >= 0)
{

    buffer_read = read...
} */

int main()
{
    int fd;

    fd = open("txt.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
}