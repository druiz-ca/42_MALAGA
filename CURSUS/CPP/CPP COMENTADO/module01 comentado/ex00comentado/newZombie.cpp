
#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    // se crea un puntero a un objeto de la clase Zombie
    Zombie *newZombie = new Zombie(name);
    // cuando se usa new se reserva memoria en el montón 
    // y se llama al constructor de la clase
    // la memoria se asigna dinamicamente y no se libera automáticamente
    // new devuelve un puntero a la dirección de memoria


    // se llama a la función announce de la clase Zombie usando -> en vez de .
    // porque newZombie es un puntero
    newZombie->announce();
    return (newZombie);
}