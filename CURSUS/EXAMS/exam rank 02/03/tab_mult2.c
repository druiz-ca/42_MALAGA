#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *cad)
{
    int i = 0;
    int res = 0;
    while (cad[i])
    {
        res = res * 10 + cad[i] - '0';
        i++;
    }
    return (res);
}

int ft_strlen(char *cad)
{
    int i = 0;
    while (cad[i])
        i++;
    return i;
}
void ft_putnbr(int num)
{
    char c;
    if (num > 9)
        ft_putnbr(num / 10);
    c = (num % 10) + '0';
    write(1, &c, 1);
}

int main(int ac, char **av)
{
    int i = 0;
    int num = 0;
    char c = '1';
    int res = 0;
    if (ac == 2)
    {
        while (c <= '9')
        {
            write(1, &c, 1);
            write(1, " x ", 3);
            write(1 ,&av[1][0], ft_strlen(av[1]));
            num = ft_atoi(av[1]);
            write(1, " = ", 3);
            ft_putnbr((c - '0') * num);
            if (c != '9')
                write(1, "\n", 1);
            c++;
        }
    }
    write(1, "\n", 1);
}