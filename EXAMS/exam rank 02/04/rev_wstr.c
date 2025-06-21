#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int cont = 0;
    char *cad;

    if (ac == 2)
    {
        cad = av[1];
        while (cad[i])
            i++;
        i--;    
        while (cad[i] == '\t' || cad[i] == ' ')
            i--;
        while (i >= 0)
        {
            if (cad[i] == ' ' && cad[i] == '\t')
                cont++;
            write(1, &cad[i--], 1);
            if (cont > 0)
                write(1, " ", 1);
            cont = 0;
        }
    }
    write(1, "\n", 1);
}