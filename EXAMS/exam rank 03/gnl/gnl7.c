#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

# define BUFFER_SIZE 42  

char *ft_get_next_line(int fd)
{
    char linea[100000];
    char buffer[BUFFER_SIZE];
    int buffer_read = 0;
    int buffer_pos = 0;
    char *res;
    int i = 0;

    if (fd <= 0 || BUFFER_SIZE <= 0)
        return (NULL);
    
    buffer_read = read(fd, buffer, BUFFER_SIZE);
    while (buffer_read > 0)
    {
        if (buffer_pos >= buffer_read)
        {
            buffer_read = read(fd, buffer, BUFFER_SIZE);
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
    int fd = open("txt.txt", O_RDONLY);
    printf("%s", ft_get_next_line(fd));
}
