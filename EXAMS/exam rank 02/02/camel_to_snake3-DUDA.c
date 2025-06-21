#include <unistd.h>

int main(int ac, char **av)
{
    char *cad;
    int i = 0;
    char c;
    if (ac == 2)
    {
        cad = av[1];
        while (cad[i])
        {
            if (cad[i] >= 'A' && cad[i] <= 'Z' && i > 0)
            {
                write(1, "_", 1);
                // PORQUE NO VA ESTO = write(1, &cad[i]+32, 1);
                c = cad[i] + 32;
                write(1, &c, 1);
            }
            else
                write(1, &cad[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}