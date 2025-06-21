#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

char *ft_itoa(int n)
{
    int i = 0;
    int temp = n;
    while (temp)
    {
        temp /= 10;
        i++;
    }
    char *str = (char *)malloc(i + 1);
    str[i] = '\0';
    while (i--)
    {
        str[i] = n % 10 + '0';
        n /= 10;
    }
    return str;
}

int main()
{
    int i = 1;
    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else
            write(1, ft_itoa(i), ft_strlen(ft_itoa(i)));
        write(1, "\n", 1);
        i++;
    }
    return 0;
}