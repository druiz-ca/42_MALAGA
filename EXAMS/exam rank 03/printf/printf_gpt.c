#include <unistd.h>
#include <stdarg.h>

void putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

void putnum(long num, int base)
{
    char *digits = "0123456789abcdef";
    char buffer[50];
    char *ptr = &buffer[49]; // wow !! así apunta ptr a la posición 49 del buffer !!!
    *ptr = '\0';

    while (num != 0)
    {
        ptr--;
        *ptr = digits[num % base];
        num /= base;
    }
    putstr(ptr);
}

void ptf(char *s, ...)
{
    va_list args;
    va_start(args, s);

    int i = 0;
    while (s[i])
    {
        if (s[i] == '%' && s[i + 1] == 's')
        {
            char *str = va_arg(args, char *);
            putstr(str);
            i++; // Skip the next character
        }
        else if (s[i] == '%' && s[i + 1] == 'd')
        {
            long num = va_arg(args, long);
            putnum(num, 10);
            i++; // Skip the next character
        }
        else if (s[i] == '%' && s[i + 1] == 'x')
        {
            long num = va_arg(args, long);
            putnum(num, 16);
            i++; // Skip the next character
        }
        else //si es "%c" no hay va_arg, solo se imprime!!!!
            write(1, &s[i], 1);
        i++;
    }
    // cuando se salta la coma despues de %s
    va_end(args);
}

int main()
{
    ptf("Hello %s, %d, %x\n", "world", 42, 42);
    return (0);
}