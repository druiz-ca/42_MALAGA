#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(char *cad)
{
    int i = 0;
    char *cad2;
    while (cad[i])
        i++;
    cad2 = malloc(sizeof(char) * i);
    i = 0;
    while (cad[i])
    {
        cad2[i] = cad[i];
        i++;
    }
    cad2[i] = '\0';
    return (cad2);
}
int main()
{
    printf("%s\n", ft_strdup("pepe"));
    // LA DIFERENCIA ENTRE EL STRCPY Y EL STRDUP, ES QUE EL DUPLICATE SOLO TE DA LA CAD A COPIAR
    //ENTONCES TIENES QUE CREAR LA NUEVA CON MALLOC, EN LA COPY YA TE DAN LAS 2 POR ESO NO MALLOC
}