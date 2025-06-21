#include <unistd.h>

void ft_putnbr(int num)
{
    int i = 0;
    char c;
    if (num > 9)
        ft_putnbr(num / 10);
    c = num % 10 + '0';
    write(1, &c, 1);
}

int esprimo(int num)
{
    int i = 2;
    if (num <= 1)
        return (0);
    while (i <= num)
    {
        if (num % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int ft_atoi(char *cad)
{
    int i = 0;
    int num = 0;

    while (cad[i])
        num = num * 10 + (cad[i++] - '0');
    return (num);
}

int main(int ac, char **av)
{
    int i, res, num = 0;
    if (ac == 2)
    {
        num = ft_atoi(av[1]);
        while (num > 0)
        {
            if (esprimo(num) == 0)
                res += num;
            num--;
        }
        ft_putnbr(res);
    }
    else
        write(1, "0", 1);
    write(1, "\n", 1);
}