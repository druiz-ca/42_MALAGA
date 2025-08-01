#include <stdio.h>
#include <stdlib.h>


char *ft_itoa2(int num)
{
    char *num_char;
    int leng = 0;
    int i = 0;
    char op;
    int n;

    if (num < 0)
    {
        leng++;
        op = '-';
        num *= -1;
    }
    n = num;
    while (n > 0)
    {
        n /= 10;
        leng++;
    }
    num_char = malloc(sizeof(char) * leng + 1);
    num_char[leng--] = '\0';
    printf("%i\n", leng);
    if (num == 0)
    {
        num_char[0] = '0';
        return (num_char);
    }
    else
        while (num > 0)
        {
            num_char[leng--] = (num % 10) + '0';
            num = num / 10;
        }
        if (op == '-')
            num_char[0] = op;
    return(num_char);
}

int main()
{
    printf("%s", ft_itoa2(-12345678));
}