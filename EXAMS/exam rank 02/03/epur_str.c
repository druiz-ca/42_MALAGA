#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int flag = 0;
    if (ac == 2)
    {
        char *cad = av[1];
        while (cad[i] == ' ' || cad[i] == '\t')
            i++;
        while (cad[i])
        {
            if (cad[i] == ' ' && cad[i] != '\0')
                flag = 1;
            if (!(cad[i] == ' ' && cad[i] != '\0'))
            {
                if (flag == 1)
                    write(1, " ", 1);
                flag = 0;
                write(1, &cad[i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}