#include <stdio.h>

int ft_strcmp(char *cad1, char *cad2)
{
    int i = 0;

    while (cad1[i] && cad2[2] && cad1[i] == cad2[i])
        i++;
    return(cad1[i] - cad2[i]);
}

int main()
{
    char *cad1 = "pepe";
    char *cad2 = "pepe";

    printf("%i", ft_strcmp(cad1, cad2));
}