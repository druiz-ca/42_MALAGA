#include <stdio.h>
#include <stdlib.h>

char f(unsigned int i, char c)
{ // me vuelve a dar fallo x olvidarme de poner el unsigned
    c -= 32;
    return (c);
}

char *ft_strmapi5(char *cad, char(*f)(unsigned int, char))
{
    int i = 0;
    char *new_cad;

    while (cad[i])
        i++;
    new_cad = malloc(sizeof(char) * i + 1);
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
    printf("%s", ft_strmapi5("hola", f));
}
