#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(char *cad)
{
    int i = 0;
    char *cad2;

    if (!cad)
        return (NULL);
    while (cad[i])
        i++;
    cad2 = malloc(sizeof (char) * i);
    cad2[i] = '\0';
    i = 0;
    while (cad[i])
    {
        cad2[i] = cad[i];
        i++;
    }
    return (cad2);
}

int main()
{
    printf("%s\n", ft_strdup("pepe"));
}