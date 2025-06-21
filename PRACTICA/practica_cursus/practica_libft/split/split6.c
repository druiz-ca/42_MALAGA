#include <stdio.h>
#include <stdlib.h>

char **ft_split6(const char *cad, char c)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **new_cad;
    int num_car;
    int num_cad;

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
            new_cad[num_cad] = malloc(sizeof(char) * num_car);
            while (j < num_car)
            {
                new_cad[num_cad][j] = cad[k];
                j++;
                k++;
            }
            num_cad++;
            i++;
            k++;
            j = 0;
            num_car = 0;
        }
        num_car++;
        i++;
    }
    return(new_cad);
}

int main()
{
    char **new_cad = ft_split6("hola que tal ", ' ');
    printf("%s", new_cad[0]);
    printf("%s", new_cad[1]);
    printf("%s", new_cad[2]);
}