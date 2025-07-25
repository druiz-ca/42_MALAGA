#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int j = 0;
    int fin = 0;
    char *cad;
    
    if (ac == 2)
    {
        cad = av[1];
        while (cad[i])
            i++;
        i--;
        j = i;
        while (cad[j] != ' ' || cad[j] != '\t')
            j--;
        j++;
        fin = j;
        while (j <= i)
            write(1, &cad[j++], 1);
    }
    write(1, "\n", 1);
}