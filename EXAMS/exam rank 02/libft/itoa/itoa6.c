#include <stdio.h>
#include <stdlib.h>

char *ft_itoa6(int num)
{
    int leng = 0;
    int op = 1;
    char *cad;
    int n;

    if(num < 0)
    {
        num *= -1;
        op *= -1;
        leng++;
    }
    n = num;
    while (n > 0)
    {
        leng++;
        n /= 10;
    }
    cad = malloc(sizeof(char) * leng + 1);
    cad[leng] = '\0';
    leng--;
    if (num == 0)
        cad[0] = '0';
    else
    {
        while (num > 0)
        {
            cad[leng--] = (num % 10) + '0';
            num /= 10;
        }
        if (op == -1)
            cad[0] = '-';
    }
    return(cad);
}

int main()
{
    printf("%s", ft_itoa6(-123));
}