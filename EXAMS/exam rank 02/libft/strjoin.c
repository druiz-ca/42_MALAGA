
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *cad)
{
    int i = 0;

    while (cad[i])
        i++;
    return (i);
}

char *ft_strjoin(char *cad1, char *cad2)
{
    int i = 0;
    int j = 0;
    char *new_cad;

    new_cad = malloc(sizeof(char) * (ft_strlen(cad1) + ft_strlen(cad2) + 1));
    if (!new_cad)
    {
        free(new_cad);
        return (NULL);
    }
    while (cad1[i])
        new_cad[j++] = cad1[i++];
    i = 0;
    while (cad2[i])
        new_cad[j++] = cad2[i++];
    new_cad[j] = '\0';
    return (new_cad);
}

int main ()
{
    char *new_cad;
    write(1, new_cad = ft_strjoin("hola", " pepe"), 9);
}