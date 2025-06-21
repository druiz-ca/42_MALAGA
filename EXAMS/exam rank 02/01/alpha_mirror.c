#include <unistd.h>
/* 'z' - cad[i]: 
    Calcula la "distancia" del carácter cad[i] a 'z'. Por ejemplo, si cad[i] es 'a', 
    entonces 'z' - 'a' es 25.
+ 'a': 
    Luego, añade esta "distancia" a 'a'. Esto da como resultado el carácter "opuesto" en el alfabeto.
    Por ejemplo, si la "distancia" es 25, entonces 'a' + 25 es 'z'.*/

int main(int ac, char **av)
{
    int i = 0;
    char *cad;
    if (ac == 2)
    {
        cad = av[1];
        while (cad[i])
        {
            if (cad[i] >= 'a' && cad[i] <= 'z')
                cad[i] = 'z' - cad[i] + 'a';
            else if (cad[i] >= 'A' && cad[i] <= 'Z')
                cad[i] = 'Z' - cad[i] + 'A';
            write(1, &cad[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}