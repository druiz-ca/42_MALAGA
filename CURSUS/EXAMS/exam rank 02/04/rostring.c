#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char c;
    int flag = 0;
    char *cad;
    char *word;

    if (ac == 2)
    {
        cad = av[1];
        while (cad[i] == ' ' || cad[i] == '\t')
        {
            i++;
            j++;
        }
        while (cad[i])
        {
            if (cad[i] == ' ' || cad[i] == '\t')
            {
                flag++;
                if (flag == 1)
                {
                    word = malloc(sizeof(char) * (i - 1 + 1));
                    while (j < i)
                    {
                        word[k] = cad[j];
                        j++;
                        k++;
                    }
                    word[k] = '\0';
                }
                else if (flag > 1)
                {
                    while (cad[i] == ' ' || cad[i] == '\t')
                        i++;
                    i--;
                    write(1, " ", 1);
                }
                k = 0;
                i++;
            }
            if (flag != 1)
                write(1, &cad[i], 1);
            i++;
        }
        j = 0;
        write(1, " ", 1);
        while (word[j])
            write(1, &word[j++], 1);
    }
    write(1, "\n", 1);
}