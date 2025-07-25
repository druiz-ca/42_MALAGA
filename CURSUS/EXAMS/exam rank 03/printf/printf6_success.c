#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>


int ft_putstr(char *cad, int i, int cont)
{
    if (!cad) // contempla el caso de que la cadena sea nula (ver diferencias con el caso de cadena vacia) 
        return (ft_putstr("(null)", 0, cont));
    if (!cad[i]) // contempla el caso de que la cadena sea vacia
        return (cont);
    while (cad[i])
    {
        write(1, &cad[i++], 1);
        cont++;
    }
    return (cont);
}
/* si recibo el num como long al hacer *-1 se le va la olla!!! */
int ft_putnum(long num, int base, int cont)
{
    char digitos[] = "0123456789abcdef";
    char res[50];
    int i = 49;

    res[i--] = '\0';
    if (num == 0)
    {
        write(1, "0", 1);
        cont++;
        return (cont);
    }
    if (num < 0 && base == 10)
    {
        write(1, "-", 1);
        num *= -1;
        cont++;
    } // si no convierto el hexadecimal a unsigned int cuando es negativo, se imprime mal
    if (num < 0 && base == 16)
        num = (unsigned int)num;
    while (num != 0)
    {
        res[i--] = digitos[num % base];
        num /= base;
    }
    i++;
    return (ft_putstr(res, i, cont));
}

int ft_printf(char *args, ...)
{
    int i = 0;
    int cont = 0;
    va_list arg;

    va_start(arg, args);
    while (args[i])
    {
        if (args[i] == '%' && args[i + 1] == 's')
        {
            cont = ft_putstr(va_arg(arg, char *), 0, cont);
            i++;
        }
        else if (args[i] == '%' && args[i + 1] == 'd')
        {
            cont = ft_putnum(va_arg(arg, int), 10, cont);
            i++;
        }
        else if (args[i] == '%' && args[i + 1] == 'x')
        {
            cont = ft_putnum(va_arg(arg, int), 16, cont);
            i++;
        }
        else
        {
            write(1, &args[i], 1);
            cont++;
        }
        i++;
    }
    va_end(arg);
    return (cont);
}

int main()
{
    printf("%i", ft_printf("Hello %s, %d, %x\n", "World", -42, -42));
}