#include <stdio.h>
#include <string.h>

/* busca en una cadena de caracteres el primer carácter que coincida con cualquier carácter
 de otra cadena de caracteres.*/

int ft_strcspn(char *cad1, char *cad2)
{
    int i = 0;
    int j = 0;

    while (cad1[i])
    {
        j = 0;
        while (cad1[j])
        {
            if (cad1[i] == cad2[j])
                return (i);
            j++;
        }
        i++;
    }
    return (0);
}

int main()
{
    printf("%i\n", ft_strcspn("manolo", "o"));
    printf("%lu\n", strcspn("manolo", "o"));
}