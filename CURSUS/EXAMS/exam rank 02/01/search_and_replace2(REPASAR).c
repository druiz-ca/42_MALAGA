#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    char *cad;
    char c1;
    char c2;
    if (ac == 4)
    {   
        cad = av[1];
        c1 = av[2][0];
        c2 = av[3][0];
        while (cad[i])
        {
            if (cad[i] == c1)
                cad[i] = c2; // se puede cambiar directamente el contenido del array
            write(1, &cad[i++], 1);
        }
    }
    write(1, "\n", 1);
}