
#include "Zombie.hpp"


/* tonto al azar.... / tonto aleatorio */
void randomChump(std::string name)
{
    // se crea un objeto de la clase Zombie llamando al constructor 
    //con el nombre que se pasa como argumento. cuando se llama al constructor
    // no se necesita poner el nombre de la función del constructor solo la clase
    Zombie zombie2(name);

    // para llamar a la función announce de la clase Zombie se usa el operador .
    // en vez de -> porque zombie2 no es un puntero
    zombie2.announce();
}