#include <unistd.h>
#include <stdarg.h>

void ft_putstr(char *cad, int i)
{
    while (cad[i])
        write(1, &cad[i++], 1);
}

void ft_putnbr(long num, int base)
{
    char digitos[] = "0123456789abcdef";
    char n[50];
    int i = 49;

    n[i--] = '\0';
    while (num != 0)
    {
        n[i--] = digitos[num % base];
        num /= base;
    }
    ft_putstr(n, ++i);
}

void my_printf(char *cad, ...)
{
    int i = 0;
    va_list args;

    va_start(args, cad);

    while (cad[i])
    {
        if (cad[i] == '%' && cad[i + 1] == 's')
        {
            ft_putstr(va_arg(args, char *), 0);
            i++;
        }
        else if (cad[i] == '%' && cad[i + 1] == 'd')
        {
            ft_putnbr(va_arg(args, long), 10);
            i++;
        }
        else if (cad[i] == '%' && cad[i + 1] == 'x')
        {
            ft_putnbr(va_arg(args, long), 16);
            i++;
        }
        else
            write(1, &cad[i], 1);
        i++;
    }
    va_end(args);
}

int main()
{
    my_printf("Hello %s %d %x", "World", 42, 42);
}