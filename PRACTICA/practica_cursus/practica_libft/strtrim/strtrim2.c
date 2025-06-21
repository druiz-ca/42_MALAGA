#include <stdio.h>
#include <stdlib.h>

char *ft_strtrim2(const char *cad, const char *cad2)
{
    int j = 0;
    int k = 0;
    int l = 0;
    int n = 0;
    char *new_cad;

    int i = 0;
    while (cad[i] && cad2[j]) // falla sin el cad2[j]
    {
        j = 0; // fallaba x no reiniciar j!!!
        while (cad2[j])
        {
            if (cad[i] == cad2[j])
                break;
            j++;
        }
        i++;
    }
    i--;
    while (cad[l])
        l++;
    l--; // menos el null
    while (cad2[n]) //n es el numero de caracteres que hay en cad2
        n++;
    n--; // menos el null
    while (n > 0)
    {
        j = 0;
        while (cad2[j])
        {
            if (cad[l] == cad2[j])
                break;
            j++;
        }
        l--;
        n--;
    }
    new_cad = malloc(sizeof(char) * l - i + 1);
    while (i < l)
        new_cad[k++] = cad[i++];
    new_cad[k] = '\0';
    return(new_cad);
}

int main()
{
    printf("%s", ft_strtrim2("manoloman", "nam"));
}