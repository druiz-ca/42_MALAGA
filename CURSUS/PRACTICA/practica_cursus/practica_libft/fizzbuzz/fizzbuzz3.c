#include <unistd.h>

int main()
{
    int num = 0;
    char n;
    char cad[3];

    while (num <= 100)
    {
        if (num == 0)
            write(1, "0", 1); // no funciona '0' como char, sino como cadena "0"
        if (num > 0 && num < 10)
        {
            n = num + '0';
            write(1, &n, 1);
        }
        if (num > 9 && num <= 100)
        {
            n = num;
            cad[1] = (n % 10) + '0';
            n /= 10;
            cad[0] = (n % 10) + '0';
            write(1, &cad, 2);
        }
        num++;
    }
}