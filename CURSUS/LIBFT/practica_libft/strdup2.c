#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *cad1 = "pepe";
    char *cad2;
    int i = 0;

    while (cad1[i])
        i++;
    cad2 = (char*)malloc(i + 1);
    i = 0;
    while (cad1[i])
    {
        cad2[i] = cad1[i];
        i++;
    }
    cad2[i] = '\0';
    printf("%s", cad2);
}