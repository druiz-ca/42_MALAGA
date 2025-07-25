#include <unistd.h>
#include <stdlib.h>

void ft_write(char *cad)
{
    while (*cad)
        write(1, cad++, 1);
}

void ft_write_num(int num)
{
    int leng = 0;
    char salto = '\n';
    int  i = 0;

    if (num < 0)
    {
        char op = '-';
        num *= -1;
        leng++;
    }
    int n = num;
    while (n > 0)
    {
        leng++;
        n /= 10;
    }
    char *cad = malloc(sizeof(char) * (leng + 1));
    cad[leng--] = '\0';
    if (num == 0)
        cad[0] = '0';
    while (num > 0)
    {
        cad[leng--] = (num % 10) + '0';
        num /= 10;
    }
    while (cad[i])
    {
        write(1, &cad[i], 1);
        i++;
    }
    write(1, &salto, 1);
}

int main()
{
    int num = 1;
    char n;
    while (num <= 100)
    {
        if (num % 15 == 0)
            ft_write("fizzbuz\n");
        if (num % 5 == 0)
            ft_write("buzz\n");
        if (num % 3 == 0)
            ft_write("fizz\n");
        else
        {
            ft_write_num(num);
        } 
        num++;
    }
}