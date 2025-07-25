#include <unistd.h>

/* tiene que comprobar si hay otra letra igual pero solo antes que ella, pq si compara despues 
se la saltara y no será correcto
*/
int comprobar1(char c, char *cad, int i)
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

int comprobar2(char c, char *cad)
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

int main(int ac, char **av)
{
    char *cad1;
    char *cad2;
    int i = 0;
    int j = 0;

    if (ac == 3)
    {
        cad1 = av[1];
        cad2 = av[2];

        while (cad1[i])
        {
            if (comprobar1(cad1[i], cad1, i) != 1)
            {
                if (comprobar2(cad1[i], cad2) == 1)
                        write(1, &cad1[i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}