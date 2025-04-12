#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
    public:
    
    void announce(void); // función que anuncia el nombre del zombie
    Zombie(std::string name); // constructor
    ~Zombie(void);  // destructor
    // cuando lleva ~ es el destructo, se llama cuando se destruye el objeto
    // el destructor se llama cuando se destruye el objeto, lo que hace es liberar
    // la memoria que se ha reservado para el objeto como un free en C

    private:

    std::string name;
};


Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif

/*
- You have to determine in what case it’s better to allocate the zombies
 on the stack(pila) or heap(montón).
- The destructor must print a message with the name of the zombie for 
debugging purposes


    // un objeto en c++ es un bloque de memoria que contiene variables y funciones
    // que se pueden acceder a través de un nombre
*/