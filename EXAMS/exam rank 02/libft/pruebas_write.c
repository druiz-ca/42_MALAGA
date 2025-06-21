#include <unistd.h>


int main()
{

    char *cad = "pepe";
    write(1, cad, 4);
    write(1, "pepe2", 5);
}// no necesito un while para imprimir la cadena!!!