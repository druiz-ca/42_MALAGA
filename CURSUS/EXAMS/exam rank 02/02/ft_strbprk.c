#include <stdio.h>
/* COMO SE RESETEA CUANDO CUENTAS SIN "I" = CAD1++ ???????? */

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
            j++; // hay que castearlo pq es un const char (sino sería return (cad))
        }
        cad1++;
    }
    return(NULL);
}

int main()
{
    printf("%s", ft_strpbrk("pepe", "e"));
}