#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *cad = "hola que";
    int i = 0;
    int j = 0;
    char c = ' ';
    char *new_cad;

    while (cad[i])
    {
        if (cad[i] == c)
        {
            new_cad = malloc(sizeof(char) * i);
            while (j < i)
            {
                new_cad[j] = cad[j];
                j++;
            }
            break;
        }
        i++;
    }
    printf("%s", new_cad);
}