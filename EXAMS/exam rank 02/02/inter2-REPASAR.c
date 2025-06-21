#include <unistd.h>

int comprobar(char c, char *cad, int i)
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

int comprobar2(char c, char *cad2)
{
    int i = 0;
    while (cad2[i])
    {
        if (c == cad2[i])
            return (1);
        i++;
    }
    return (0);
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
        {   // enviar la pos de i para comprobar si antes de esa pos. había otra letra = y saltarla
            if (comprobar(cad1[i], cad1, i) == 1)
            {
                if (comprobar2(cad1[i], cad2) == 1)
                    write(1, &cad1[i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}