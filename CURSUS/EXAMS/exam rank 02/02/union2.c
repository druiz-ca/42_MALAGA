#include <unistd.h>

int comprobar2(char c,  char *cad)
{
    int i = 0;
    while (cad[i])
    {
        if (cad[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int comprobar1(char *cad, char c, int i)
{
    int cont = 0;
    while (i >= 0)
    {
        if (cad[i] == c)
            cont++;
        i--;
    }
    return (cont);
}

int main(int ac, char **av)
{
    char *cad1;
    char *cad2;
    int i = 0;

    if (ac == 3)
    {
        cad1 = av[1];
        cad2 = av[2];
        while (cad1[i])
        {
            if (comprobar1(cad1, cad1[i], i) == 1)
                write(1, &cad1[i], 1);
            i++;
        }
        i = 0;
        while (cad2[i])
        {
            if (comprobar1(cad2, cad2[i], i) == 1)
            {
                if (comprobar2(cad2[i], cad1) == 0)
                    write(1, &cad2[i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}