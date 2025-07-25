#include <stdio.h>

char *ft_strrev(char *cad)
{
    int i = 0;
    int j = 0;
    char aux;

    while (cad[i])
        i++;
    i--; // AL NO RESTAR EL '\0' NO IMPRIMIA NADA!!! = EL NULL
    while (j < i)
    {
        aux = cad[j];
        cad[j] = cad[i];
        cad[i] = aux;
        j++;
        i--;
    }
    return (cad);
}

int main()
{ /* si envio la cadena directa ("manolo") da bus error pq al enviarla así se envía como const char 
    para modificarla hay que enviarla asi: cad = "manolo"
*/
    char cad[] = "manolo";
    printf("%s\n", ft_strrev(cad));
}