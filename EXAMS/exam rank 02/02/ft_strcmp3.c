#include <stdio.h>
#include <string.h>

int ft_strcmp(char *cad1, char *cad2)
{
    int i = 0;
    while (cad1[i] && cad2[i] && cad1[i] == cad2[i])
        i++;
    return (cad1[i] - cad2[i]);
}
int main()
{
    printf("%i\n", ft_strcmp("manolo", "manolo"));
    printf("%i\n", strcmp("manolo", "manolo"));
}