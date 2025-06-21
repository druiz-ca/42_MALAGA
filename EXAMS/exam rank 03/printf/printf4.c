
#include <unistd.h>
#include <stdarg.h>

void ft_putstr(char *cad, int i)
{
    while (cad[i])
        write(1, &cad[i++], 1);
}

void ft_putnbr(long num, int base)
{
    char *digitos = "0123456789abcdef";
    char cad[50];
    int i = 49;

    cad[i--] = '\0';
    while (num != 0)
    {
        cad[i--] = digitos[num % base];
        num /= base;
    }
    i++;
    ft_putstr(cad, i);
}

void ft_printf(char *cad, ...)
{

    va_list args;
    va_start(args, cad);
    int i = 0;
    int j = 0;
    while (cad[i])
    {
        if (cad[i] == '%' && cad[i + 1] == 's')
        {
            ft_putstr(va_arg(args, char *), j);
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
    ft_printf("Hola %s %d %x\n", "Mundo", 42, 42);
}