#include "gnl1.h"

char *gnl(int fd)
{
    char linea[70000];
    static char buffer[BUFFER_SIZE];
    int buffer_read;
    int buffer_pos;
    int i = 0;
    char *res;

    i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if (buffer_pos >= buffer_read)
        {
            buffer_read = read(fd, buffer, BUFFER_SIZE);
            if (buffer_read <= 0)
                break;
            buffer_pos = 0;
        }
        linea[i] = buffer[buffer_pos];
        i++;
        buffer_pos++;
    }
    linea[i] = '\0';
    if (i == 0)
        return (NULL);
    res = linea;
    return (res);
}

int main()
{
    int fd = open("txt.txt", O_RDONLY);
    printf("%s", gnl(fd));
}