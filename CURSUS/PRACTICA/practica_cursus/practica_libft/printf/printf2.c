#include <unistd.h>
#include <stdarg.h>

void my_printf(const char *cad, ...)
{
    va_list lista_arg;
    va_start(lista_arg, cad);
    while (*cad)
    {
        if (*cad == '%')
        {
            cad++;
            if (*cad == 'c')
            {
                char c = va_arg(lista_arg, int); //el char no funciona, aunque sea char se extrae con int...
                write(1, &c, 1);
            }
            if (*cad == 'i')
            {
                int n = va_arg(lista_arg, int);
                n += '0'; // no termino de entender porque funciona esto con write al ser n un int, es que el '0' le cambia el tipo??
                write(1, &n, 1);
            }
            if (*cad == 's')
            {
                char *cad2 = va_arg(lista_arg, char*);
                while (*cad2)
                    write(1, cad2++, 1);
            }
        }
        else
            write(1, cad, 1); //cad es la cadena entera pero ademas es un puntero !??! si imprimo 4 posiciones imprime toda la cadena?!?!
        cad++;
    }
    va_end(lista_arg);
}

int main()
{ // si pruebas a poner otro car especial distinto de % no se pone en blanco, no lo detecta!!!
    my_printf("hola %c %i %s", 'c', 5, "pepe");
}