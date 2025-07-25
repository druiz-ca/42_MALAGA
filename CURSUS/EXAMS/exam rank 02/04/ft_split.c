#include <stdio.h>
#include <stdlib.h>

char **ft_split(char *cad, char c)
{
    char **new_cad;
    int i = -1;
    int j = 0;
    int k = 0;
    int l = 0;
    int cont = 0;

    while (cad[i])
    {
        i++;
        if (cad[i] == c || cad[i] == '\0')
            cont++;
    }
    new_cad = malloc(sizeof (char *) * cont);
    i = -1;
    while (cad[i])
    {
        i++;
        if (cad[i] == c || cad[i] == '\0')
        {
            new_cad[j] = malloc(sizeof(char) * (i - k));
            while (k < i)
                new_cad[j][l++] = cad[k++];
            new_cad[j][l] = '\0';
            j++;
            k++;
            l = 0;
        }
    }
    return (new_cad);
}

int main()
{
    char **cad = ft_split("pepe que tal", ' ');
    printf("%s\n", cad[0]);
    printf("%s\n", cad[1]);
    printf("%s\n", cad[2]);
}