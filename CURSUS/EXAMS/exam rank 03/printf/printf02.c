#include <unistd.h>
#include <stdarg.h>


void ft_putstr(char *cad, int i)
{
    while (cad[i])
        write(1, &cad[i++], 1);
}

void ft_putnum(long num, int base)
{
    char *digitos = "0123456789abcdef";
    char cad[50];
    int i = 49;

    cad[i--] = '\0';
    if (num == 0)
        cad[i--] = '0';
    while (num != 0)
    {
        cad[i--] = digitos[num % base];
        num/= base;
    }
    i++;
    ft_putstr(cad, i);
}

void ft_printf(char *cad, ...)
{
    va_list args;
    va_start(args, cad);
    int i = 0;

    while (cad[i])
    {
        if (cad[i] == '%' && cad[i + 1] == 's')
        {
            char *str = va_arg(args, char *);
            ft_putstr(str, 0);
            i++;
        }
        else if (cad[i] == '%' && cad[i + 1] == 'd')
        {
            long num = va_arg(args, long);
            ft_putnum(num, 10);
            i++;
        }
        else if (cad[i] == '%' && cad[i + 1] == 'x')
        {
            long num = va_arg(args, long);
            ft_putnum(num, 16);
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
    char *cad = "World";
    ft_printf("Hello, %s, %d, %x\n", cad, 42, 42);
}