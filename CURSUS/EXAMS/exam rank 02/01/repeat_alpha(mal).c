#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    char *cad;
    int cont = 0;
    if (ac == 2)
    {
        cad = av[1];
        while (cad[i])
        {
            cont = cad[i] - 'a' + 1;
            while (cont > 0)
            {
                write(1, &cad[i], 1);
                cont--;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}