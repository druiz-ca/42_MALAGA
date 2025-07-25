#include <stdio.h>

int ft_atoi(char *cad)
{
    int dst;
    int i = 0;
//HONDA VFR + nt + ' '
    while (cad[i] == ' ' || cad[i] == '\t' || cad[i] == '\f'
     || cad[i] == '\r' || cad[i] == '\n' || cad[i] == '\v')
        i++;
    while (cad[i] == '-' || cad[i] == '+')
        i++;
    while(cad[i] >= '0' && cad[i] <= '9')
    {
        dst = dst * 10 + (cad[i] - '0');
        i++;
    }
    return (dst);
}

int main()
{
    char *cad = " -123";
    printf("%i", ft_atoi(cad));
}