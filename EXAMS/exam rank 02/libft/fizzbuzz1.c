#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_write(char tipo, int num)
{
    char *fb = "fizzbuzz\n";
    char *f = "fizz\n";
    char *b = "buzz\n";
    char salto = '\n';
    char *cad;
    int leng = 0;
    char op;
    int i = 0;

    if (tipo == 'v')
    {
        while (fb[i])
            write(1, &fb[i++], 1);
    }
    if (tipo == 'f')
    {
        while (b[i])
            write(1, &b[i++], 1);
    }
    if (tipo == 'b')
    {
        while (f[i])
            write(1, &f[i++], 1);
    }
    if (tipo == 'n')
    {
        int n = num;
        while (n > 0)
        {
            leng ++;
            n /= 10;
        }
        if (num < 0)
        {
            leng++;
            op = '-';
            num *= -1;
        } 
        cad = malloc(sizeof(char) * (leng + 1));
        cad[leng--] = '\0';
        if (num == 0)
            cad[0] = '0';
        else
        {
            while (num > 0)
            {
                cad[leng--] = (num % 10) + '0';
                num /= 10;
            }
        }
        if (op == '-')
            cad[0] = op;

        while (cad[i])
            write(1, &cad[i++], 1);
        write(1, &salto, 1);
    }
    return ;
}
int main()
{
    int num = 0;

    while (num <= 100)
    {
        if (num % 15 == 0)
            ft_write('v', num);
        else if (num % 5 == 0)
            ft_write('b', num);
        else if (num % 3 == 0)
            ft_write('f', num);
        else
            ft_write('n', num);
        num++;
    }
}