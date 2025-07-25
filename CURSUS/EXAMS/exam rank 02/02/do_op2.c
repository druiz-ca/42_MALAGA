#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int i = 0;
    int num1 = 0;
    int num2 = 0;
    char op;

    if (ac == 4)
    {
        num1 = atoi(av[1]);
        op = av[2][0];
        num2 = atoi(av[3]);

        if (op == '+')
            printf("%i", num1 + num2);
        if (op == '-')
            printf("%i", num1 - num2);
        if (op == '*')
            printf("%i", num1 * num2);
        if (op == '/')
            printf("%i", num1 / num2);
    }
    printf("\n");
}