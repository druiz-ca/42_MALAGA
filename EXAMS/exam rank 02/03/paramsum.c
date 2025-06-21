#include <unistd.h>

void ft_putnbr(int ac)
{
    char c;
    if (ac > 9)
        ft_putnbr(ac / 10);
    c = (ac%10) + '0';
    write(1, &c, 1);
}

int main(int ac, char **av)
{
    int i = 0;
    int cont  = 0;

    if (ac >= 2)
        ft_putnbr(ac - 1);
    else
        write(1, "0", 1);
    write(1, "\n", 1);
}