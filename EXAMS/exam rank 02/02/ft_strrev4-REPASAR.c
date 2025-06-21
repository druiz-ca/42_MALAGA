#include <stdio.h>

char *ft_strrev(char *cad)
{
    char aux;
    int i = 0;
    int j = 0;
    while (cad[i])
        i++;
    i--;
    while (j < i)
    {
        aux = cad[j]; // se puede cambiar el contenido de la cadena en "directo"
        cad[j] = cad[i];
        cad[i] = aux;
        i--;
        j++;
    }
    return (cad);
}

int main()  // daba bus error porque enviaba directamente a la función la cad ("manolo") y asi no la 
            //puede modificar
{
    char cad[] = "manolo"; // si le pongo tamaño a la cad me falla 
    printf("%s\n", ft_strrev(cad));
}