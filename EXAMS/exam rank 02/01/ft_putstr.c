#include <unistd.h>

void ft_putstr(char *cad)
{
    int i = 0;
    while (cad[i])
        write(1, &cad[i++], 1);
}