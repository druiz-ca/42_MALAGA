#include <stdio.h>
#include <stdlib.h>

int main(int ac, char** av)
{
    int num1 = 0;
    int num2 = 0;
    char op;
    int res = 0;
    int i = 0;
    if (ac == 4)
    {
        num1 = atoi(av[1]);
        num2 = atoi(av[3]);
        op = av[2][0];
        if (op == '+')
            printf("%i", num1 + num2);
        else if (op == '-')
            printf("%i", num1 - num2);
        else if (op == '*')
            printf("%i", num1 * num2);
        else if (op == '/')
            printf("%i", num1 / num2);
    }
    printf("\n");
}