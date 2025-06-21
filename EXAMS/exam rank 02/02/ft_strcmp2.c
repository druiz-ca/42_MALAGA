#include <stdio.h>
/* devuelve la diferencia del primer carácter diferente que encuentre */
int ft_strcmp(char *cad1, char *cad2)
{
    while (*cad1 && *cad2 && *cad1 == *cad2)
    {
           cad1++;
           cad2++;
    }
    return (*cad1 - *cad2);
}

int main()
{
    printf("%i", ft_strcmp("pepe", "pepa"));
}