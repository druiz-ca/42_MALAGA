#include <stdio.h>

int max(int *cad, int len)
{
    int num = 0;
    int i = 0;

    while (i <= len)
    {
        if (cad[i] > num)
            num = cad[i];
        i++;
    }
    return (num);
}

int main()
{
    int cad[] = {1, 2, 3};
    printf("%i\n", max(cad, 2));
}