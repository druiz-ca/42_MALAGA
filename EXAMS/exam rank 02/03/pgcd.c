#include <stdio.h>
#include <stdlib.h>

int check(int n, int i)
{
    if (n % i == 0)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    int n1 = 0;
    int n2 = 0;
    int i = 2;
    int mcd = 0;
    if (ac == 3)
    {
        n1 = atoi(av[1]);
        n2 = atoi(av[2]);

        while (i < n1)
        {
            if (check(n1, i) == 1 && check(n2, i) == 1)
                mcd = i;
            i++;
        }
        if (mcd == 1)
            printf("1");
        else
            printf("%i", mcd);
    }
    printf("\n");
}