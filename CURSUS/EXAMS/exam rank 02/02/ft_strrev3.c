#include <stdio.h>
#include <string.h>

char *ft_strrev(char *cad)
{
    int j = 0;
    int i = 0;
    char aux;

    while (cad[i])
        i++;
    i--;
    while (i > j)
    {
        aux = cad[j];
        cad[j] = cad[i];
        cad[i] = aux;
        j++;
        i--;
    }
    return(cad);
}

int main()
{
    char cad[] = "manolo";
    printf("%s\n", ft_strrev(cad));

}