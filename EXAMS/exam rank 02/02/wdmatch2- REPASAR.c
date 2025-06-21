#include <unistd.h>

int comprobar(char c, char *cad, int i)
{
    while (cad[i])
    {
        if (cad[i] == c)
            return (1);
        i++;
    }
    return(0);
}

int main(int ac, char **av)
{
    char *cad1;
    char *cad2;
    int i = 0;
    static int j = 0; // paso el indice STATIC asi se mantiene en su pos cuando hago el checking
    if (ac == 3)
    {
        cad1 = av[1];
        cad2 = av[2];

        while (cad1[i])
        {
            if (comprobar(cad1[i], cad2, j) == 1)
                write(1, &cad1[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}