
#include "Zombie.hpp"
/* los constructores o destructores no necesitan especificar que es void a
diferencia de otra función cualquiera */
Zombie::Zombie(std::string name)
{
    this->name = name;
    // no es obligatorio usar this->, se puede poner solo name = name;
    // se usa this-> para diferenciar entre la variable name de la clase Zombie
    // y la variable name que se pasa como argumento
    std::cout << this->name << ": has been created." << std::endl;
}

/* los constructores o destructores no necesitan especificar que es void a
diferencia de otra función cualquiera */
Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " has been destroyed" << std::endl;
}

// cuando una funcion esta declarada dentro de una clase,
// se tiene que poner el nombre de la clase seguido de :: y el nombre de la función
void Zombie::announce(void)
{
    std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
    // se usa this-> para acceder a la variable name de la clase Zombie
}
/* 
- Como las funciones están declaradas dentro de una clase, hay que poner
el nombre de la clase seguido de :: y el nombre de la función

- this-> es un puntero que apunta a la dirección de memoria del objeto
que llama a la función, se usa para acceder a los miembros de la clase
que están ocultos por otros miembros con el mismo nombre
*/