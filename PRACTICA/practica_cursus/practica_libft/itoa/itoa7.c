#include <stdio.h>
#include <stdlib.h>

char *ft_itoa7(int num)
{
    char *new_cad;
    int leng = 0;
    int op = 0;
    int n;

    if (num < 0)
    {
        op = -1;
        num *= -1;
        leng++; 
    } // no imprimia xq no aumentaba leng para darle espacio al '-'!!!
    n = num;
    while (n > 0)
    {
        leng++;
        n /= 10;
    }
    new_cad = malloc(sizeof(char) * leng + 1);
    new_cad[leng--] = '\0';
    if (num == 0)
        new_cad[0] = '0';
    while (num > 0)
    {
        new_cad[leng--] = (num % 10) + '0';
        num /= 10;
    }
    if (op == -1)
        new_cad[0] = '-';
    return(new_cad);
}

int main()
{
    printf("%s", ft_itoa7(-1234));
}