#include <stdio.h>
#include <stdlib.h>

char **ft_split5(const char *cad, char c)
{
    char **new_cad;
    int i;
    int j;
    int k;
    int num_cad;
    int num_car;


    while (cad[i])
    {
        if(cad[i] == c)
            j++;
        i++;
    }
    new_cad = (char **)malloc(sizeof(char *) * j);
    i = 0; //X NO INICIALIZAR NO IBA!!!!!!!!!
    j = 0;
    k = 0;
    num_car = 0;
    num_cad = 0;
    while (cad[i])
    {
        if (cad[i] == c)
        {
            new_cad[num_cad] = malloc(sizeof(char) * num_car);
            while (j < num_car) // OTRA FORMA DE MEDIRLO!!!!
            {
                new_cad[num_cad][j] = cad[k];
                j++;
                k++;
            }
            new_cad[num_cad][j] = '\0';
            j = 0;
            k++;
            i++; // NUEVO: SUMO 1 A I PARA EL ESPACIO
            num_cad++;
            num_car = 0; // RESETEO EL NUM DE CARACTERES
        }
        num_car++;
        i++;
    }
    return(new_cad);
}

int main()
{
    char** new_cad = ft_split5("hola que tal ", ' ');
    printf("%s", new_cad[0]);
    printf("%s", new_cad[1]);
    printf("%s", new_cad[2]);
}