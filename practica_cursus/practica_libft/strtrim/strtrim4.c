#include <stdio.h>
#include <stdlib.h>

int ft_check(char c, char *cad2)
{
    int i = 0;
    while (cad2[i])
    {
        if (cad2[i] == c)
            return (1);
        else
            i++;
    }
    return (0);
}

char *ft_strtrim4(char *cad, char *cad2)
{
    int start = 0;
    int fin = 0;
    int j = 0;
    char *new_cad;

    if (!cad || !cad2)
        return (NULL);
    while (cad[start])
        fin++;
    fin--; // me olvido de esto
    start = 0;
    while (cad[start] && ft_check(cad[start], cad2))
        start++;
    while (fin > start && ft_check(cad[fin], cad2))
        fin--;
    new_cad = malloc(sizeof(char) * (fin - start) + 1);
    if (!new_cad)
        return (NULL);
    while (start <= fin)
        new_cad[j++] = cad[start++];
    new_cad[j] = '\0';
    return(new_cad);
}

int main()
{
    printf("%s", ft_strtrim4("manolo", "man"));
}