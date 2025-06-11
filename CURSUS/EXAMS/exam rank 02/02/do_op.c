#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
    int num1;
    char op;
    int num2;
    int res = 0;
    if (ac == 4)
    {
        num1 = atoi(av[1]);
        op = av[2][0];
        num2 = atoi(av[3]);
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