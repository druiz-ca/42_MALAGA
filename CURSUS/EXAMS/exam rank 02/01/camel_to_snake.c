#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    char *cad;
    if (ac == 2)
    {
        cad = av[1];
        while (cad[i])
        {
            if (cad[i] >= 'A' && cad[i] <= 'Z')
                write(1, "_", 1);
            write(1, &cad[i++], 1);
        }
    }
    write(1, "\n", 1);
}