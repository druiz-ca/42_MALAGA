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
            if (cad[i] >= 'a' && cad[i] <= 'z')
            {
                c = 'z' - cad[i] + 'a';
                write(1, &c, 1);
            }
            else 
            if (cad[i] >= 'A' && cad[i] <= 'Z')
            {     
                c = 'Z' - cad[i] + 'A';
                write(1, &c, 1);
            }
            else
                write(1, &cad[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}