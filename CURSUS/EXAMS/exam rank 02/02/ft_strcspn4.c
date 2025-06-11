#include <stdio.h>

size_t ft_strcspn(char *cad1, char *cad2)
{
    int i = 0;
    int j = 0;

    while (cad1[i])
    {
        j = 0;
        while (cad2[j])
        {
            if (cad1[i] == cad2[j])
                return(i);
            j++;
        }
        i++;
    }
    return(i);
}

int main()
{
    printf("%zu\n", ft_strcspn("pepa", "a"));
}