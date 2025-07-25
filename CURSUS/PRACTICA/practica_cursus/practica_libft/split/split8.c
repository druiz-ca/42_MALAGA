#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    int num_cad = 0;
    int num_char = 0;
    char *cad = "hola que tal ";
    char c = ' ';

    while (cad[i])
    {
        if (cad[i] == c)
            num_cad++;
        i++;
    }
    char **new_cad = malloc(sizeof(char) * num_cad);
    i = 0;
    num_cad = 0;
    while (cad[i])
    {
        if (cad[i] == c)
        {
            new_cad[num_cad] = malloc(sizeof(char) * (num_char + 1));
            while (num_char > 0)
            {
                new_cad[num_cad][j++] = cad[k++];
                num_char--;
            }
            new_cad[num_cad++][j] = '\0';
            i++;
            k++;
            j = 0;
        }
        num_char++;
        i++;
    }
    printf("%s\n", new_cad[0]);
    printf("%s\n", new_cad[1]);
    printf("%s\n", new_cad[2]);

}