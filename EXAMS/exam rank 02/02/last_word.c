#include <unistd.h>

int main(int ac, char **av)
{
    char *cad;
    int i = 0;

    if (ac == 2)
    {
        cad = av[1];
        while (cad[i])
            i++;
        i--;
        while (i >= 0)
        {
            if (cad[i] == 0 || cad[i] == ' ' || cad[i] == '\t')
            {
                i++;
                while (cad[i])
                    write(1, &cad[i++], 1);
                break;
            }
            i--;
        }
    }
    write(1, "\n", 1);
}