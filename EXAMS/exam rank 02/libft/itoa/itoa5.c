#include <stdio.h>
#include <stdlib.h>

char *ft_itoa5(int num)
{
    int n;
    int leng;
    char *cad;
    int op;

    if (num < 0)
    {
        num *= -1;
        op = '-';
        leng++;
    }
    n = num;
    while (n > 0)
    {
        leng++;
        n /= 10;
    }
    cad = malloc(sizeof(char) * leng + 1);
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
        if (op == '-')
            cad[0] = op;
    }
    return (cad);
}

int main()
{
    printf("%s", ft_itoa5(1234));
}