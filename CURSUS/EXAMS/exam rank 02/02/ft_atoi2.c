#include <unistd.h>
#include <stdio.h>


int main(int ac, char **av)
{
    int i = 0;
    char *cad;
    int num = 0;
    int op = 1;
    if (ac == 2)
    {
        cad = av[1];
        while (cad[i] == ' ' || cad[i] == '\t')
            i++;
        if (cad[i] == '+' || cad[i] == '-')
        {
            if (cad[i] == '-')
                op = -1;
            i++;
        }
        while (cad[i] >= '0' && cad[i] <= '9')
        {
            num = num * 10 + (cad[i] - '0');
            i++;
        }
    }
    return (num * op);
}