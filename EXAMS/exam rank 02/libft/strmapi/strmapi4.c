#include <stdio.h>
#include <stdlib.h>

char f(unsigned int i, char c)
{
    c -= 32;
    return (c);
}

char *ft_strmapi(char *cad, char (*f)(unsigned int, char))
{
    int i;
    char *new_cad;
    i = 0;
    while (cad[i])
        i++;
    new_cad = malloc(sizeof(char) * i);
    i = 0;
    while (cad[i])
    {
        new_cad[i] = f(1, cad[i]);
        i++;
    }
    return (new_cad);
}

int main()
{
    printf("%s", ft_strmapi("holaque tal", f));
}