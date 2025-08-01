#include <stdio.h>
#include <stdlib.h>

char f(unsigned int i, char c)
{//me fallaba solo xq no había puesto unsigned!!!!!
   if (i > 0)
        c = c -32;
    return (c);
}

char *ft_strmapi3(const char *cad, char (*f)(unsigned int, char))
{
    int i = 0;
    char *new_cad;

    while (cad[i])
        i++;
    new_cad = malloc(sizeof(char) * i + 1);
    i = 0;
    while (cad[i])
    {
        if (cad[i] != ' ')
        {
            new_cad[i] = f(5, cad[i]);
            i++;
        }
        else if (cad[i] == ' ')
            i++;
    }
    new_cad[i] = '\0';
    return(new_cad);
}

int main()
{
    printf("%s", ft_strmapi3("holapepe", f));
}