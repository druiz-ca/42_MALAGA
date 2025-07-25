#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *cad)
{
        int num = 0;
        int i = 0;
        if (cad[0] == '0' || cad[0] == '-')
                return (0);
        while (cad[i])
                i++;
        i--;
        while (i >= 0)
                num = num * 10 + (cad[i--] - '0');
        return (num);
}

int ft_primo(int num)
{
        int aux = 2;
        if (num <= 1)
                return (0);
        while (aux <= num)
        {      
                if (num % aux == 0)
                        return (1);
                aux--;
        }
        return (0);

}

void ft_putnbr(int num)
{
        char n;
        while (num > 9)
                ft_putnbr (num / 10);
        n = num + '0';
        write(1, &n, 1);

}

int main(int ac, char **av)
{
        int num;
        int sum = 0;
        if (ac == 2)
        {
                num = ft_atoi(av[1]);
                while (num > 0)
                {
                        if (ft_primo(num) == 1)
                                sum += num;
                        num--;
                }
                ft_putnbr(sum);
        }
        write(1, "\n", 1);
}