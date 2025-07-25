#include <stdio.h>
#include <stdlib.h>

char **ft_split7(char *cad, char c)
{
    char **new_cad;
    int num_cad = 0;
    int num_car = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    while (cad[i++])
    {
        if(cad[i] == c)
            num_cad++;
    }
    new_cad = (char **)malloc(sizeof(char *) * num_cad);
    i = 0;
    num_cad = 0;
    while (cad[i])
    {
        if(cad[i] == c)
        {   // me habia olvidad de hacer malloc a cada array (num_car-- > 0)
            new_cad[num_cad] = malloc(sizeof(char) * (num_car + 1));
            while (num_car-- > 0) //uso numcar como contador
                new_cad[num_cad][j++] = cad[k++];
            new_cad[num_cad++][j] = '\0';
            j = 0;
            num_car = 0;
            k++;
            i++;
        }
        num_car++;
        i++;
    }
    return(new_cad);
}

int main()
{
    char **new_cad = ft_split7("hola que tal ", ' ');
    printf("%s", new_cad[0]);
    printf("%s", new_cad[1]);
    printf("%s", new_cad[2]);
}