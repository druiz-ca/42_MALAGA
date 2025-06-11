#include <unistd.h>

void ft_putnbr(int num)
{
    char c;
    char *cad;
    int i = 0;
    if (num >= 10)
        ft_putnbr (num / 10);
    c = num % 10 + '0';
    write(1, &c, 1);
}

int main()
{
    int num = 1;

    while (num <= 100)
    {
        if (num % 5 == 0 && num % 3 == 0)
            write(1, "fizzbuzz", 8);
        if (num % 5 == 0)
            write(1, "buzz", 4);
        else if (num % 3 == 0)
            write(1, "fizz", 4);
        else
            ft_putnbr(num);
        write(1, "\n", 1);
        num++;
    }
}