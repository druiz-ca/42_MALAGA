#include <unistd.h>

int comprobar_duplicado(char c, char *cad, int i)
{
    i--;
    while (i >= 0)
    {
        if (cad[i] == c)
            return (1);
        i--;
    }
    return (0);
}

int comprobar_duplicado2(char c, char *cad1)
{
    int i = 0;
    while (cad1[i])
    {
        if (cad1[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    int i = 0;
    char *cad1;
    char *cad2;

    if (ac == 3)
    {
        cad1 = av[1];
        cad2 = av[2];

        while (cad1[i])
        {
            if (comprobar_duplicado(cad1[i], cad1, i) == 0)
                write(1, &cad1[i], 1);
            i++;
        }
        i = 0;
        while (cad2[i])
        {
            if (comprobar_duplicado(cad2[i], cad2, i) == 0)
            {
                if (comprobar_duplicado2(cad2[i], cad1) == 0)
                    write(1, &cad2[i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}