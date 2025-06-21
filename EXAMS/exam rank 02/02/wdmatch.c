#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int j = 0;
    char *cad1;
    char *cad2;

    if (ac == 3)
    {
        cad1 = av[1];
        cad2 = av[2];

        while (cad2[i])
        {
            if (cad2[i] == cad1[j])
                j++;
            i++;
        }
        if (cad1[j] == '\0')
        {
            i = 0;
            while (cad1[i])
                write(1, &cad1[i++], 1);
        }
    }
    write(1, "\n", 1);
}