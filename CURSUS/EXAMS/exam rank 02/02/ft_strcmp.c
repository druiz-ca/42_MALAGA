#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2)
{
    while (*s1)
    {
        if (*s1 != *s2)
            return (1);
        s1++;
        s2++;
    }
    return (0);
}

int main()
{
    printf("%i\n", ft_strcmp("pepe", "pepe"));
    printf("%i\n", strcmp("pepe", "pepe"));
}