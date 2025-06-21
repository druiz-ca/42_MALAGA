#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int i = 0;
    char *cad;
    char c;
    //c = 65; los char no admiten +d1 carácter pero si más de un número!!! xq equivale a un char
    // PQ 
    if (ac == 2)
    {
        cad = av[1];
        while (cad[i])
        {
            if (cad[i] >= 'a' && cad[i] <= 'z')
                c = 'z' + 'a' - cad[i]; // z + a - letra ???? 'o 122- 65 + letra
            else if (cad[i] >= 'A' && cad[i] <= 'Z')
                c = 'Z' + 'A' - cad[i];
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
}