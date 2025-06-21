#include <unistd.h>

int main(int ac, char **av)
{
    int i, j, flag = 0;
    char *cad;
    if (ac == 2)
    {
        cad = av[1];
        while (cad[i] == ' ' || cad[i] == '\t')
            i++;
        while(cad[j])
            j++;
        while (cad[j] == ' ' || cad[j] == '\t')
            j--;
        while (i <= j)
        {
            flag = 0;
            while (cad[i] == ' ' || cad[i] == '\t')
            {
                flag = 1;
                i++;
            }
            if (flag == 1)
                write(1, "   ", 1);
            if (cad[i] >= 'a' && cad[i] <= 'z')
                write(1, &cad[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}