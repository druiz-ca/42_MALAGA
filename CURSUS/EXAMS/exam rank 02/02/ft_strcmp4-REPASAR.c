#include <stdio.h>

int ft_strcmp(char *cad1, char *cad2)
{
    int i = 0;
    while (*cad1 && *cad2 && *cad1 == *cad2)
    {
        cad1++;
        cad2++;
    }
    return (*cad1 - *cad2); // al restar esto sale la diferencia entre un caracter y otro ?!?!
                            // + facil de ver = cad[i] - cad2[i] ( es decir: 'a' - )
}

int main()
{
    printf("%i\n", ft_strcmp("a", "z"));
}