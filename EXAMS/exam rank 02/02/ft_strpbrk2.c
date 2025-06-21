#include <stdio.h>
#include <string.h>

char *ft_strpbrk(const char *cad1, const char *cad2)
{
    int j = 0;
    while (*cad1)
    {
        j = 0;
        while (cad2[j])
        {
            if (*cad1 == cad2[j])
                return (char *)cad1;
            j++; //funciona sin castear pero da alerta
        }   // la alerta la da pq al ser const char no me deja hacer ningun cambio 
        // ni de la posición inicial del puntero a la cadena!! x eso castearla x char * normal!!!!
        cad1++;
    }
    return (NULL);
}

int main()
{
    printf("%s\n", ft_strpbrk("pepe", "e"));
    printf("%s\n", strpbrk("pepe", "e"));
}