#include <stdio.h>
#include <stdlib.h>

int ft_comprobar(char *cad2, char c)
{
    int i = 0;
    while(cad2[i])
    {
        if (cad2[i] == c)
            return (1);
        else
            i++;
    }
    return (0);
}

char *ft_strtrim3(char *cad, char *cad2)
{
    char *new_cad;
    int start = 0;
    int j = 0;
    int fin = 0;

    if (!cad || !cad2)
        return (NULL);
    while (cad[j++])
        fin++;
    fin--;
    j = 0; // comporbar devuelve 1 si son iguales (1 != '\0')
    // este while, en el momento que sea distinto el char sale
    while (cad[start] && ft_comprobar(cad2, cad[start])) // porque corta en start 3 como maximo?? x el cad[start]??
        start++;
    while (fin > start && ft_comprobar(cad2, cad[fin]))
        fin--;
    new_cad = malloc(sizeof(char) * (fin - start) + 1);
    if(!new_cad)
        return (NULL);
    while (start <= fin) // error: no ponia <= y me faltaba la ultima letra!
        new_cad[j++] = cad[start++];
    new_cad[j] = '\0';
    return(new_cad);
}

int main()
{ // trim = recrotar
    printf("%s", ft_strtrim3("manolom", "nam"));
}