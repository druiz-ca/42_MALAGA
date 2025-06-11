#include <unistd.h>

void ft_putstr(int n)
{
    char c;

    if (n > 9)
        ft_putstr(n / 10);
    c = n % 10 + '0'; // pq necesita el % 10 ??
    write(1, &c, 1);
}

int main()
{
    int i = 1;

    while (i <= 100)
    {
        if (i % 5 == 0 && i % 3 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else
            ft_putstr(i);
        write(1, "\n", 2);
        i++;
    }
}