#include "gnl.h"

char *get_next_line(int fd)
{
    char *res;
    static char buffer[BUFFER_SIZE];
    char line[5000];
    int i = 0;
    int buffer_read = 0;
    int buffer_pos = 0;
    
    buffer_read = read(fd, buffer, BUFFER_SIZE);
    while (buffer_read > 0)
    {
        if (buffer_pos >= buffer_read)
        {
            buffer_read = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
        }
        line[i++] = buffer[buffer_pos++];
    }
    line[i] = '\0';
    res = line;
    return (res);
}

int main()
{
    int fd = open("txt.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
}