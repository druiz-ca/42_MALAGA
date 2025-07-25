#include <unistd.h>

int main(int ac, char **av)
{
    char *cad;
    int i= 0;
    int j = 0;

    if (ac == 2)
    {
        cad = av[1];
        while (cad[i] == ' ' || cad[i] == '\t')
            i++;
        j = i;
        while (cad[i] != ' ')
            i++;
        while (j < i)
            write(1, &cad[j++], 1);
    }
    write(1, "\n", 1);
}