#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    char *cad;
    int aux = 0;
    int cont = 0;
    if (ac == 2)
    {
        cad = av[1];
        while (cad[i] == ' ')
            i++;
        while (cad[i] && cad[i] != ' ')
            write(1, &cad[i++], 1);
    }
    write(1, "\n", 1);

}