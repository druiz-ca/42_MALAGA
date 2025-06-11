#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(char *cad1)
{
    int i = 0;
    char *cad2;
    while (cad1[i])
        i++;
    cad2 = malloc(sizeof(char) * i);
    cad2[i] = '\0';
    i = 0;
    while (cad1[i])
    {
        cad2[i] = cad1[i];
        i++;
    }
    return (cad2);
}

int main()
{
    printf("%s\n", strdup("pepe"));
    printf("%s\n", ft_strdup("pepe"));
}