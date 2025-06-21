/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:21:59 by daniel            #+#    #+#             */
/*   Updated: 2025/02/09 12:52:59 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::endl;
using std::string;
using std::cin;

// constructor por defecto
ClapTrap::ClapTrap()
{
    cout << "ClapTrap default constructor called" << endl;
    this-> _attackDamage = 20; // inicializa el daño de ataque
    this-> _energyPoints = 50; // inicializa los puntos de energía
    this-> _hitPoints = 100; // inicializa los puntos de vida
}

// constructor con parámetro
ClapTrap::ClapTrap(string name)
{
    cout << "ClapTrap parameterized constructor called, and named: " << name << endl;
    this-> _name = name; // inicializa el nombre
    this-> _attackDamage = 20; // inicializa el daño de ataque
    this-> _energyPoints = 50; // inicializa los puntos de energía
    this-> _hitPoints = 100; // inicializa los puntos de vida
}

// constructor de copia
ClapTrap::ClapTrap(const ClapTrap &copyClapTrap)
{
    cout << "ClapTrap copy constructor called, and cloned " << copyClapTrap.getName() << endl;
    *this = copyClapTrap;
    // como este metodo se llama desde el main, se copia el objeto que se le pasa
    // como parametro al objeto que se crea
    // entonces this es el objeto que se crea y copyClapTrap es el objeto que se pasa
}

// destructor (sino hay metodo para el destructor NO FUNCIONA!!! )
ClapTrap::~ClapTrap()
{
    cout << "ClapTrap destructor called, and destroyed: " << this->_name << endl;
}

/* sobrecarga del operador de asignación
    - el primer caltrap& es el tipo de retorno y es por referencia
    - la diferencia entre OPERATOR= y COPY CONSTRUCTOR es que uno es para crear
        un objeto y el otro es cuando ya existe y se quiere asignar los valores
        de otro objeto existente
    - en cpp cuando se devuelve un obj por referencia no se usa * sino &
    porque se devuelve la dirección de memoria del objeto
*/
ClapTrap& ClapTrap::operator= (const ClapTrap &copyClapTrap)
{
    cout << "ClapTrap assignment operator called, and assigned: " << copyClapTrap.getName() << endl;
    
    // la copia la hago usando los metodos getName y luego setName
    this-> setName(copyClapTrap.getName());
    this-> setAttackDamage(copyClapTrap.getAttackDamage());
    this-> setEnergyPoints(copyClapTrap.getEnergyPoints());
    this-> setHitPoints(copyClapTrap.getHitPoints());
    return *this; // devuelve el objeto que se ha creado por referencia
    // en este caso si se usa * porque se devuelve el objeto en si
}

// sets y gets
// método para obtener el nombre
    // este const es porque no se va a modificar el objeto 
    //( en vez de ir delante del parentesis va al final de la función)
const string& ClapTrap::getName() const 
{
    return (this->_name);
}

// método para obtener los puntos de vida
unsigned int ClapTrap::getHitPoints() const
{
    return (this->_hitPoints);
}

// método para obtener los puntos de energía
unsigned int ClapTrap::getEnergyPoints() const
{
    return (this->_energyPoints);
}

// método para obtener el daño de ataque
unsigned int ClapTrap::getAttackDamage() const
{
    return (this->_attackDamage);
}

// método para establecer el nombre
void ClapTrap::setName(const string &name)
{
    this->_name = name;
}

// método para establecer los puntos de vida
void ClapTrap::setHitPoints(unsigned int num)
{
    this->_hitPoints = num;
}

// método para establecer los puntos de energía
void ClapTrap::setEnergyPoints(unsigned int num)
{
    this->_energyPoints = num;
}

// método para establecer el daño de ataque
void ClapTrap::setAttackDamage(unsigned int num)
{
    this->_attackDamage = num;
}

// ser reparado
void ClapTrap::beRepaired(unsigned int amount)
{
    this->_hitPoints += amount;
    cout << "ClapTrap " << this->_name << " has been repaired by " << amount << " points!" << endl;
}

// recibir daño
void ClapTrap::takeDamage(unsigned int amount)
{   // solo si tiene mas vida que el daño que le hacen se lo resta sino lo pone a 0
    if (amount > this->_hitPoints)
    {   // solo muesta que le quitan la vida(salud) que le quedaba: HITPOINTS
        cout << "ClapTrap " << this->_name << " takes " << this->_hitPoints << " points of damage!" << endl;
        this-> _hitPoints = 0;
    }
    else
    {// muesta la vida que le quitan AMOUNT
        cout << "ClapTrap " << this-> _name << " takes " << amount << " points of damage!" << endl;
        this->_hitPoints -= amount;
    }
}

// atacar. recibe como parametro el nombre del objetivo al que se va a atacar
void ClapTrap::attack(const string &target)
{
    if (this->_energyPoints < 2) // si no tiene suficiente energía no puede atacar
    {
        cout << "ClapTrap " << this->_name << " is trying to attack " << target << ", but is out of energy points!" << endl;
        return ;
    }
    else if (this-> _hitPoints <= 0) // sino tiene vida no puede atacar
    {
        cout << "ClapTrap " << this->_name << " is trying to attack " << target << ", but is out of hit points... is dead!" << endl;
        return ;
    }
    else // cada vez que ataques pierdes 2 puntos de energía
    {
        cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << endl;
        this->_energyPoints -= 2;
    }
}