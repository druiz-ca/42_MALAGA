#include <stdio.h>
#include <string.h>

size_t ft_strcspn(const char *cad1, const char *cad2)
{
    size_t i = 0;
    int j = 0;

    while (cad1[i])
    {
        j = 0;
        while (cad2[j])
        {
            if (cad1[i] == cad2[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}

int main()
{
    printf("%lu\n", ft_strcspn("anola", "l"));
    printf("%lu\n", strcspn("anola", "l"));
}