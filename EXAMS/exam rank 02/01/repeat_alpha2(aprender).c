#include <unistd.h>

int main(int ac, char **av)
{
    char *cad;
    int i = 0;
    int cont = 1;

    if (ac == 2)
    {
        cad = av[1];
        while (cad[i])
        {
            if (cad[i] >= 'a' && cad[i] <= 'z')
                cont = cad[i] - 'a' + 1; // al restar x '0' en vez de x 'a' daba error!!!!
            else if (cad[i] >= 'A' && cad[i] <= 'Z') //si es MAY entonces - 'A'
                cont = cad[i] - 'A' + 1;           
            else
                cont = 1;
            while (cont--)
                write(1, &cad[i], 1); // habia puesto que el nº de char fuese cont-- entonces imprimia raro
            i++;
        }
    }
    write(1, "\n", 1);
}