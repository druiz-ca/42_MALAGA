#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    char *cad;
    char a;
    char b;
    if (ac == 4)
    {
        cad = av[1];
        a = av[2][0];
        b = av[3][0];
        while (cad[i])
        {
            if (cad[i] == a)
                write(1, &b, 1);
            else
                write(1, &cad[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}