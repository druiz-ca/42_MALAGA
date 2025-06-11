#include <stdio.h>
#include <stdlib.h>

int ft_atoi5(char *cad)
{
    int num = 0;
    int i = 0;
    char op;
    while (cad[i] == '\n' || cad[i] == '\t' || cad[i] == ' ' || cad[i] == '\v' || cad[i] == '\f' || cad[i] == '\r')
        i++;
    while (cad[i] == '-')
    {
        i++;
        op = '-';
    }
    while (cad[i] >= '0' && cad[i] <= '9')
    {
        num = num * 10 + (cad[i] - '0');
        i++;
    }
    if (op == '-')
        num *= -1;
    return(num);
}

int main()
{
    printf("%i", ft_atoi5("-1234"));
}