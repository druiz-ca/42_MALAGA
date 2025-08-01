#include <stdio.h>
#include <stdlib.h>

int ft_atoi4(const char *cad)
{
    int i = 0;
    int op;
    int num = 0;

    while (cad[i] == ' ' || cad[i] == '\n' || cad[i] == '\t' || cad[i] == '\v' || cad[i] == '\f' || cad[i] == '\r')
        i++;
    while (cad[i] == '-')
    {
        i++,
        op = '-';
    } // no puede ser 10 x1 serian 2 digitos y ya no seria un char sino un string!! y llevaria " "
    while (cad[i] >= '0' && cad[i] <= '9')
    {
        num = num * 10 + (cad[i] - '0');
        i++;
    }
    if (op == '-')
        num *= -1;
    return (num);
}

int main()
{
    printf("%i", ft_atoi4("-123"));
}