
#include <unistd.h>

char *ft_strchr(char *cad, char c)
{
    while (*cad)
    {
        if (*cad == c)
            return (cad);
        cad++;
    }
    if (!*cad)
        return (NULL);
    return (NULL);
}

int main()
{
    write(1, ft_strchr("manolo", 'o'), 3);
}