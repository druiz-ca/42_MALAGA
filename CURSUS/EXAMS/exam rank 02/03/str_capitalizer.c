#include <unistd.h>

void funcion(char *cad)
{
    int i = 0;
    int j = 0;
    int flag = 1;

    while (cad[i] == ' ' || cad[i] == '\t')
        i++;
    while (cad[j])
        j++;
    while (cad[j] == ' ' || cad[j] == '\t')
        j--;
    if (cad[i] >= 'a' && cad[i] <= 'z')
        cad[i] -= 32;
    write(1, &cad[i++], 1);
    while (i <= j)
    {
        flag = 0;
        while (cad[i] == ' ' || cad[i] == '\t')
        {
            flag++;
            i++;
        }
        if (cad[i] >= 'A' && cad[i] <= 'Z')
            cad[i] += 32;
        if (cad[i] >= 'a' && cad[i] <= 'z' && cad[i-1] == ' ' || cad[i-1] == '\t')
            cad[i] -= 32;
        if (flag > 0)
            write(1, " ", 1);
        write(1, &cad[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    int i = 1;

    if (ac > 1)
    {
        while (av[i])
            funcion(av[i++]);
    }
    write(1, "\n", 1);
}