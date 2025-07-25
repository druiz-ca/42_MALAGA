#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(char *cad1)
{
    char *cad2;
    int i= 0;
    while (cad1[i])
        i++;
    cad2 = malloc(sizeof(char) * i);
    i = 0;
    while (cad1[i])
    {
        cad2[i] = cad1[i];
        i++;
    }
    cad2[i] = '\0';
    return (cad2);
}

int main()
{
    printf("%s", ft_strdup("pepe"));
}