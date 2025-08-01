#include <stdio.h>

int main()
{
    char dst[20];
    char *cad = "pepe";
    int n = 4;
    int i = 0;

    while (cad[i] && i < n)
    {
        dst[i] = cad[i];
        i++;
    }
    printf("%s", dst);
}