#include <stdio.h>
#include <stdlib.h>

int ft_atoi3(char *cad)
{
    int i = 0;
    int num = 0;

    while (cad[i] == ' ' || cad[i] == '\n' || cad[i] == '\v' || cad[i] == '\f' || cad[i] == '\r' || cad[i] == '\t')
        i++;
    while (cad[i] == '-')
        i++;
    while(cad[i] >= '0' && cad[i] <= '9')
    { // no funciona poner NUM *= 10 + ......
        num = num * 10 + (cad[i] - '0'); // le añade un 0 al final como "unidades" y a este le suma la "unidad" de cad[i]
        i++; // num (0) * 10 = 0 + cad[i] esto pone el 1er digito
    }
    return (num);
}

int main()
{
    printf("%i\n", ft_atoi3(" -123"));
}