#include <unistd.h>
#include <stdarg.h>

void ft_putnum(long num, int base)
{
    char *digitos = "0123456789abcdef";
    char buffer[50];
    int i = 49; // que bueno!!! evito un bucle!!!
    
    buffer[i--] = '\0';
    if (num == 0)
        buffer[i--] = '0';
    while (num != 0)
    {
        buffer[i--] = digitos[num % base];
        num = num / base;
    }
    i++;
    while (buffer[i])
        write(1, &buffer[i++], 1);
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

void my_printf(char *str, ...)
{
    va_list args;
    va_start(args, str);

    int i = 0;
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1] == 's')
        {   //a va_arg se le pasa la estructura args, no la cadena str
            char *c = va_arg(args, char *);
            write(1, c, ft_strlen(c));
            i++;
        }
        else if (str[i] == '%' && str[i + 1] == 'd')
        {
            long num = va_arg(args, long);
            ft_putnum(num, 10);
            i++;
        }
        else if (str[i] == '%' && str[i + 1] == 'x')
        {
            long num = va_arg(args, long);
            ft_putnum(num, 16);
            i++;
        }
        else
            write(1, &str[i], 1);
        i++;
    }
    va_end(args);
}

int main()
{
    char *c = "world";
    my_printf("Hello %s, %d, %x\n", c, 42, 42);
}