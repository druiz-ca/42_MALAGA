#include <stdio.h>
#include <string.h>
/* 
- busca en una cadena de caracteres el primer carácter que coincida con cualquier 
    carácter de otra cadena de caracteres.
- Devuelve un puntero al primer carácter en s1 que coincide con cualquier carácter en s2.
*/

char *ft_strpbrk(char *cad1, char *cad2)
{
    int j = 0;

    while (*cad1)
    {
        j = 0;
        while (cad2[j])
        {
            if (*cad1 == cad2[j])
                return (cad1);
            j++;
        }
        cad1++;
    }
    return (NULL);
}

int main()
{
    printf("%s\n", strpbrk("manolo", "o"));
    printf("%s\n", ft_strpbrk("manolo", "o"));
}