#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *cad = "hola que tal ";
    char **new_cad;
    char c = ' ';
    int i;
    int j;
    int k;
    int num_array;
    int num_car;

    i = 0;
    j = 0;
    k = 0;
    num_array = 0;
    num_car = 0;

    while (cad[i])
    {
        if (cad[i] == c)
            j++;
        i++;
    }
    new_cad = (char **)malloc(sizeof(char *) * j);
    i = 0;
    j = 0;
    while (cad[i])
    {
        if (cad[i] == c)
        {
            new_cad[num_array] = malloc(sizeof(char) * num_car);
            while (k < i)
            {
                new_cad[num_array][j] = cad[k];
                j++;
                k++;
            }
            new_cad[num_array][j] = '\0';
            num_array++;
            j = 0;
            k++;
        }
        num_car++;
        i++;
    }
    printf("%s\n", new_cad[0]);
    printf("%s\n", new_cad[1]);
    printf("%s\n", new_cad[2]);
}