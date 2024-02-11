#include <stdio.h>
#include <unistd.h>

void ft_escribir(char *cad)
{
    int i = 0;
    while (cad[i])
        write(1, &cad[i++], 1);
}

void ft_escribir_num(int n)
{
    char num;
    char salto = '\n';
    if (n < 10)
    {
        num = n + '0';
        write(1, &num, 1);
        write(1, &salto, 1);
    }
    else
    {
        num = (n / 10) + '0';
        write(1, &num, 1);
        num = (n % 10) + '0';
        write(1, &num, 1);
        write(1, &salto, 1);

    }
}

int main()
{
    int n = 1;
    while (n <= 100)
    {
        if (n % 15 == 0) // sino se pone este el 1º nunca lo imprime
            ft_escribir("fizzbuzz\n");
        else if (n % 3 == 0)
            ft_escribir("fizz\n");
        else if (n % 5 == 0)
            ft_escribir("buzz\n");
        else
            ft_escribir_num(n); // no funciona poner aqui n++;
    n++;
    }
}