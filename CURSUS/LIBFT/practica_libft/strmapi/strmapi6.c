#include <stdio.h>
#include <stdlib.h>

char f(unsigned int i, char c)
{
    c-= 32;
    return (c);
}

char *ft_strmapi6(char *cad, char(*f)(unsigned int, char))
{
    char *new_cad;
    int i = 0;

    while (cad[i++]);
    new_cad = malloc(sizeof(char) * (i + 1));
    i = 0;
    while (cad[i])
    {
        new_cad[i] = f(i, cad[i]);
        i++;
    }
    return(new_cad);
}

int main()
{
    printf("%s", ft_strmapi6("holaque tal", f));
}