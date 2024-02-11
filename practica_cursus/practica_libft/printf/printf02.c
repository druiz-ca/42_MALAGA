#include <unistd.h>
#include <stdarg.h>

void ft_printf(const char* contenido, ...)
{
    va_list argumentos;
    int c;

    va_start(argumentos, contenido);
    while (*contenido)
    {
        if(*contenido == '%')
        {
            contenido++;
            switch(*contenido)
            {
                case 'c':
                {
                    c = (char)va_arg(argumentos, int);
                    write(1, &c, 1);
                    break;
                }
                case 's':
                {
                    char *cad = va_arg(argumentos, char *);
                    while (*cad)
                    {
                        write(1, cad, 1);//la cad no lleva &
                        cad++;
                    }
            }
            }
        }
        else
        {
            write(1, contenido, 1);
        }
        contenido++;
    }
    va_end(argumentos);
}

int main()
{
    ft_printf("hola %c %s", 'a', "pepe");
}