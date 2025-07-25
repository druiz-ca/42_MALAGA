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
    char numero[50];
    int i = 49;
    numero[i--] = '\0';

    if (num == 0)
    {
        write(1, "0", 1);
        return;
    }
    while (num != 0)
    {
        numero[i--] = digitos[num % base];
        num /= base;
    }
    i++; // por no avanzar no imprimia!!!
    ft_putstr(numero, i);
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
            char *cadena = va_arg(args, char *);
            ft_putstr(cadena, j);
            i++;
        }
        else if (cad[i] == '%' && cad[i + 1] == 'd')
        {
            long num = va_arg(args, long);
            ft_putnbr(num, 10);
            i++;
        }
        else if (cad[i] == '%' && cad[i + 1])
        {
            long num = va_arg(args, long);
            ft_putnbr(num, 16);
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
    char *str = "World";
    ft_printf("Hello, %s, %d, %x\n", str, 42, 42);
}