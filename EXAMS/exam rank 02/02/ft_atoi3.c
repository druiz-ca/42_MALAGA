#include <stdio.h>

int ft_atoi(char *cad)
{
    int i = 0;
    int num = 0;
    int op = 1;
    while (cad[i] && (cad[i] == ' ' || cad[i] == '\t'))
        i++;
    if (cad[i] == '-')
        op *= -1;
    if (cad[i] == '-' || cad[i] == '+')
        i++;
    while (cad[i] >= '1' && cad[i] <= '9')
    {
        num = num * 10 + cad[i] - '0';
        i++;
    }
    return (num);
}

int main()
{
    printf("%i", ft_atoi("   -123"));
}