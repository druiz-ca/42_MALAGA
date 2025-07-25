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
            if ((cad[i] >= 'a' && cad[i] <= 'z') || (cad[i] >= 'A' && cad[i] <= 'Z'))
            {
                if (cad[i] == 'z')
                    c = 'a';
                else if (cad[i] == 'Z')
                    c = 'A';
                else
                    c = cad[i] + 1;
            }
            else
                c = cad[i];
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
}