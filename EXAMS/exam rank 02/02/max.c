#include <stdio.h>

int max(int *cad, int len)
{
    int i = 0;
    int big = 0;

    while (i <= len)
    {
        if (cad[i] > big)
            big = cad[i];
        i++;
    }
    return (big);
}

int main()
{
    int array[4] = {1,4,2,6};
    printf("%i", max(array, 4));
}