#include <stdarg.h>
#include <unistd.h>

void myprintf(const char *cad, ...)
{
    va_list lista_arg;
    va_start(lista_arg, cad);
    int i = 0;
    
    while (cad[i])
    {
        if (cad[i] == '%')
        {
            i++;
            if (cad[i] == 'c')
            {
                int c = va_arg(lista_arg, int);
                write(1, &c, 1);
            }
        }
        else
            write(1, &cad[i], 1);
        i++;
    }
}

int main()
{
    myprintf("hola %c %c", 'a', 'b');
}