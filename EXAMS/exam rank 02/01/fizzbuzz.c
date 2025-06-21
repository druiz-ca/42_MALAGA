#include <unistd.h>
#include <stdlib.h>
int longitud(char *cad)
{
    int i = 0;
    while (cad[i])
        i++;
    return (i);
}

char *print_num(int num)
{
    int n = 0;
    int cont = 0;
    n = num;
    char *cad;
    while (n > 0)
    {
        cont++;
        n /= 10;
    }
    cad = malloc(sizeof(char) * cont);
    while (num > 0)
    {
        cad[cont--] = (num % 10) + '0';
        num /= 10;
    }
    return (cad);
}

int main()
{
    int num = 1;
    char *n;
    while (num <= 100)
    {
        if (num % 5 == 0 && num % 3 == 0)
            write(1, "fizzbuzz\n", 9);
        else if (num % 5 == 0)
            write(1, "fizz\n", 5);
        else if (num % 3 == 0)
            write(1, "buzz\n", 5);
        else
        {
            write(1, (print_num(num)), longitud(print_num(num)));
            write(1, "\n", 1);
        }
        num++;
    }
}