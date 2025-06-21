#include <stdio.h>

int ft_atoi(const char *cad) // const para bloquera la cad y no poder modificarla = PERMISO DE SOLO LECTURA!!
{
    int num;
    char op;
    int i = 0;
    if (cad[i] == ' ' || (cad[i] >= 9 && cad[i] <= 13)) // recordar estos son todos los /t, /v etc
        i++;
    if (cad[i] == '+' || cad[i] == '-')
    {
        if (cad[i] == '-')
            op = '-';
        i++;
    }
    while (cad[i] >= '0' && cad[i] <= '9')
        num = num * 10 + cad[i++] - '0'; // num *= 10 NO VA?!?!?
    if (op == '-')
        num *= -1;
    return(num);
}

int main()
{
    printf("%i", ft_atoi(" -123"));
}