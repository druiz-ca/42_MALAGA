#include <stdio.h>
#include <stdlib.h>

/* SPLIT = DIVIDIR */
int ft_strlen(char *cad, char c)
{
    int i = 0;
    int num_array = 0;

    while (cad[i])
    {
        if (cad[i] == c)
            num_array++;
        i++;
    }
    return (num_array);
}

char **ft_split(char *cad1, char c)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int num_array= 0;
    int num_car = 0;
    char **new_cad;

    new_cad = (char **)malloc(ft_strlen(cad1, c) * sizeof(char *));

    while (cad1[i])
    {
        if (cad1[i] == c)
        {
            new_cad[num_array] = malloc(sizeof(char) * num_car);
            while (k < i)
            {
                new_cad[num_array][j] = cad1[k];
                k++;
                j++;
            }
            new_cad[num_array][j] = '\0';
            k++;
            j = 0;
            num_array++;
            num_car = 0;
        }
        i++;
        num_car++;
    }
    return(new_cad);
}

int main()
{
    char *cad1 = "hola que tal ";
    char c = ' ';
    char **new_cad;
    
    new_cad = ft_split(cad1, c);
    printf("%s\n", new_cad[0]);
    printf("%s\n", new_cad[1]);
    printf("%s\n", new_cad[2]);
}
