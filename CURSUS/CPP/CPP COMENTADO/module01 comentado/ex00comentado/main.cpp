/* ejercicio para ver las diferencias entre crear una clase/objeto mediante
new y borra con delete y crearla directamente por defecto */
#include "Zombie.hpp"

int main()
{
    // con new se crea una objeto en el montón: memoria dinámica que no se 
    // libera automáticamente y permanece hasta que se libera explícitamente
    Zombie *zombie1 = newZombie("zombie 1"); 


    // crea un objeto en la pila: memoria estática que se libera automáticamente
    // solo dura mientras la función está en ejecución
    randomChump("zombie 2");
    delete zombie1;
}