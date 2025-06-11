#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int num)
{
    char *cad;
    int i = 0;
    int n = 0;
    int len = 0;
    char op;

    n = num;
    if (num == 0)
        return ("0");
    if (num < 0)
    {
        num *= -1;
        op = '-';
    }
    while (n > 0) 
    {
        len++;
        n /= 10;
    }
    cad = malloc(sizeof(char) * (len + 1));
    cad[len--] = '\0';
    while (num > 0)
    {
        cad[len] = num % 10 + '0';
        len--;
        num /= 10;
    }
    return (cad);
}
int main()
{
    printf("%s", ft_itoa(24));
}