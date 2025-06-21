#include <stdio.h>
#include <string.h>

char *ft_strpbrk(char *cad1, char *cad2)
{
    int j = 0;
    while (*cad1)
    {
        j = 0;
        while (cad2[j])// la 2a cad no se puede mover como la 1 x puntero pq sino no se reinicia!!!!
        {
            if (*cad1 == *cad2)
                return (cad1); //así se devuelve el puntero apuntando donde haya encontrado la coincidencia
            j++;
        }
        cad1++;
    }
    return (NULL); // cuando la funcion devuelve un char * el return es NULL, si devuelve int es 0
}

int main()
{
    printf("%s\n", ft_strpbrk("pepa", "e"));
    printf("%s\n", strpbrk("pepa", "e"));
}