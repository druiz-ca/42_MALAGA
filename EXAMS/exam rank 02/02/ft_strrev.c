#include <stdio.h>
#include <string.h>

char *ft_strrev(char *cad)
{
    int i = 0;
    int len = 0;
    char tmp;

    while (cad[len])
        len++;
    while (i < cad[len] / 2)
    {
        tmp = cad[i];
        cad[i] = cad[len - 1 - i];
        cad[len - 1 - i] = tmp;
        i++;
    }
    return (cad);
}

int main()
{
    printf("%s\n", ft_strrev("manolo"));
}