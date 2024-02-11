// directivas de preprocesador para incluir los archivos de encabezado
// proporciona las macros para manejar la lista de argumentos de longitud variable
#include <stdarg.h>
#include <stdio.h>

void my_printf(const char *format, ...)
{ // ... indica que la función tiene un número variable de argumentos
    va_list args; // variable de tipo va_list para acceder a los argumentos de la función
    va_start(args, format); 
    //le envío args y format a va_start para que sepa dónde comienza la lista
    //de argumentos

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    int c = va_arg(args, int);
                    putchar(c);
                    break;
                }
                case 's': {
                    char *string = va_arg(args, char *);
                    printf("%s", string);
                    break;
                }
                case 'p': {
                    void *ptr = va_arg(args, void *);
                    printf("%p", ptr);
                    break;
                }
                case 'd': {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    break;
                }                   
                case 'i': {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    break;
                }
                case 'u': {
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%u", num);
                    break;
                }
                case 'x': {
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%x", num);
                    break;
                }
                case 'X': {
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%X", num);
                    break;
                }
                case '%':
                    putchar('%');
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    break;
            }
        } else {
            putchar(*format);
        }
        format++;
    }

    va_end(args);
}

int main()
{
    my_printf("Hello, %s! You are %d years old.\n", "Alice", 25);
    my_printf("Character: %c, Pointer: %p, Unsigned: %u, Hex: %x, HEX: %X, Percent: %%\n", 'A', &main, 12345, 12345, 12345);
    return 0;
}