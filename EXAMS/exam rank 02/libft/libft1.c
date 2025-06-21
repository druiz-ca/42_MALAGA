#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return (c);
}
int ft_tolower(int c)
{
    if(c >= 'A' && c <= 'Z')
        c += 32;
    return (c);
}
int ft_isdigit(int n)
{
    if (n >= 0 && n <= 9)
        return (0);
    else
        return (1);
}
int ft_isalnum(int n)
{
    if ((n >= 'a' && n <= 'z') || (n >= 0 && n <= 9))
        return (0);
    else
        return (1);
}
int ft_isalpha(int c)
{
    if (c >= 'a' && c <= 'z')
        return (0);
    else
        return (1);
}
int ft_isascii(int n)
{
    if (n >= 0&& n <= 128)
        return (0);
    else
        return (1);
}
int ft_isprint(int n)
{
    if (n < 32 && n < 126)
        return (0);
    else
        return (1);
}
void ft_bzero(void *cad, size_t num)
{
    char *p;
    int i;

    i = 0;
    p = cad;
    while (num > 0)
    {
        p[i++] = '\0';
        num--;
    }
}
int ft_strlen(char *cad)
{
    int i = 0;
    while (cad[i])
        i++;
    return (i);
}
char *ft_strchr(char *cad, char c)
{
    while (cad)
    {
        if (*cad == c)
            return (cad);
        cad++;
        if (*cad == '\0')
            return (NULL);
    }
    return (NULL);
}
char *ft_strdup(const char *cad)
{
    char *new_cad;
    int i;
    int j;

    i = 0;
    j = 0;

    while (cad[i])
        i++;
    new_cad = malloc(sizeof(char) * (i + 1));
    i = 0;
    while (cad[i])
        new_cad[j++] = cad[i++];
    return (new_cad);
}
size_t ft_strlcat(char *dest, char *cad, size_t longdest)
{
    size_t i, j, longdest_aux;
    longdest_aux = 0;
    i = 0;
    j = 0;

    while (dest[i] && i < longdest)
        i++;
    longdest_aux = i;
    while (cad[j])
        dest[i++] = cad[j++];
    dest[i] = '\0';
    return (i);
}
size_t ft_strlcpy(char *dest, char *cad, size_t longdest)
{
    size_t i = 0;
    if (longdest == 0)
        return (ft_strlen(cad));
    while (cad[i] && i < longdest)
    {
        dest[i] = cad[i];
        i++;
    }
    dest[i] = '\0';
    return (i);
}
char *ft_strjoin(char *cad1, char *cad2)
{
    int i = 0;
    int j = 0;
    char *new_cad;

    new_cad = malloc(sizeof(char) * (ft_strlen(cad1) + ft_strlen(cad2) + 1));
    while (cad1[i])
        new_cad[j++] = cad1[i++];
    i = 0;
    while (cad2[i])
        new_cad[j++] = cad2[i++];
    new_cad[j] = '\0';
    return (new_cad);
}
char *ft_striteri(char *cad, void (*f)(int, char*))
{
    int i = 0;
    while (cad[i])
        f(i, cad);
    return (cad);
}
int ft_buscar(char c, char *cad2)
{
    int i = 0;
    while (cad2[i])
    {
        if (cad2[i++] == c)
            return (1);
    }
    return (0);
}
char *ft_strtrim(char *cad1, char *cad2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *new_cad;

    while (cad1[i] && (ft_buscar(cad1[i], cad2) == 0))
        i++;
    j = ft_strlen(cad1);
    while (j > i && (ft_buscar(cad1[j], cad2) == 0))
        j--;
    new_cad = malloc(sizeof(char) * (j - i + 1));
    while (i <= j)
        new_cad[k++] = cad1[i++];
    new_cad[k] = '\0';
    return (new_cad);
}
char *ft_strnstr(char *cad1, char *cad2, int longitud)
{
    int i = 0;
    int j = 0;

    while (cad1[i])
        i++;
}


int main()
{
    printf("%c\n", ft_toupper('a'));
    printf("%c\n", ft_tolower('A'));
    printf("%i\n", ft_isdigit('a'));
    printf("%i\n", ft_isalnum('a'));
    printf("%i\n", ft_isalpha(0));
    printf("%i\n", ft_isascii(0));
    printf("%i\n", ft_isprint(0));
    printf("strlen: %i\n", ft_strlen("pepe"));
    char cad[4] = "pepe";
    ft_bzero(cad, 3);
    printf("bzero: %s\n", cad);
    printf("strchr: %s\n", ft_strchr("pepe", 'e'));
    printf("strdup: %s\n", ft_strdup("pepe"));
    char dest[7] = "manolo ";
    printf("strlcat: %zu\n", ft_strlcat(dest, "pepe", sizeof(dest)));
    //zu para imprimir size_t
    printf("strlcpy: %zu\n", ft_strlcpy(dest, "pepe", 0));
    printf("strjoin: %s\n", ft_strjoin("pepe", "manolo"));
    //printf("striteri: %s\n", ft_striteri(cad, f)); // pte
    printf("strtrim: %s", ft_strtrim("manoloman", "olo"));
    printf("strnstr: %s", ft_strnstr("donde esta pepe", "pe", 3));
}

