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
    int num_char;

    i = 0;
    j = 0;
    k = 0;
    num_array = 0;
    num_char = 0;

    while (cad[j]) // x recorrer con puntero *cad daba NULL!!!
    {
        if (cad[j] == c)
            i++;
        j++;
    }
    new_cad = (char **)malloc(sizeof(char *) * i);
    i = 0;
    j = 0;
    while (cad[i])
    {
        if (cad[i] == c)
        {
            new_cad[num_array] = malloc(sizeof(char) * num_char);
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
            num_char = 0;
        }
        num_char++;
        i++;
    }
    printf("%s\n", new_cad[0]);
    printf("%s\n", new_cad[1]);
    printf("%s\n", new_cad[2]);
}
