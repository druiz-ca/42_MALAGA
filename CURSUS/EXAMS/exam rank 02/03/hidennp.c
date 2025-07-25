#include <unistd.h>

int comprobar (char *cad1, char *cad2)
{
    int i = 0;
    int j = 0;
    while (cad1[i])
    {
        while (cad2[j])
        {
            if (cad1[i] == cad2[j])
            {
                j++;
                break;
            }
            j++;
        }
        i++;
        if (cad2[j] == '\0')
            return (0);
        if (cad1[i] == '\0')
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    char *cad1;
    char *cad2;
    if (ac == 3)
    {
        cad1 = av[1];
        cad2 = av[2];
        if (comprobar(cad1, cad2) == 1)
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
    write(1, "\n", 1);
}