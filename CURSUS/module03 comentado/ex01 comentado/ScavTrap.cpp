/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:22:18 by daniel            #+#    #+#             */
/*   Updated: 2025/02/09 14:03:13 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using std::cout;
using std::endl;
using std::string;


// constructor por defecto
    // se llama al constructor de la clase base ClapTrap
    // se inicializan los valores de la clase base antes de los de la clase derivada
    // para que no haya problemas con la herencia 
ScavTrap::ScavTrap() : ClapTrap()
{
    cout << "ScavTrap default constructor called" << endl;
}

// constructor con parámetro
    // se crea un objeto de la clase base ClapTrap con el nombre que se pasa como parametro
    // y con los valores por defecto de la clase base
ScavTrap::ScavTrap(const string &name) : ClapTrap(name)
{
    cout << "ScavTrap " << name << " has been created." << endl;
}

// CONSTRUCTOR POR COPIA
    // const tambien se usa para que no se modifique el objeto, no solo variables
    //LISTA DE INICIALIZACION : para inicializar los atributos de la clase base
    // antes de entrar en el cuerpo del constructor
        // : ClapTrap llama al const. de copia de la clase base y le para
        // el nuevo objeto que se pasa como parametro
        // el constructor, en funcion del parametro que reciba, usa uno u otro!!
ScavTrap::ScavTrap(const ScavTrap &copyScavTrap) : ClapTrap(copyScavTrap)
{
    cout << "ScavTrap copy constructor called." << endl;
}
/* TAMBIEN SE PUEDE HACER SIN LISTA DE INICIALIZACION:
    ScavTrap::ScavTrap(const ScavTrap &copyScavTrap)
    {
        *this = copyScavTrap; <------ se llama al operador de asignación
        cout << "ScavTrap copy constructor called." << endl;
    } 
*/

// destructor
ScavTrap::~ScavTrap()
{   // usa getName que es un metodo de la clase base
    cout << "ScavTrap " << this->getName() << " has been destroyed." << endl;
}

// METODO GUARDAR PUERTA
    // no modifica los valores del objeto, por eso lleva const
void ScavTrap::guardGate() const
{
    cout << "ScavTrap " << this->getName() << " has entered in Gate Keeper Mode." << endl;
}

// METODO DE ATAQUE
    // no modifica los valores del objeto, por eso lleva const
void ScavTrap::attack(const string &target)
{
    if (this->_energyPoints < 5)
    {
        cout << "ScavTrap " << this->getName() << " has no energy points left." << endl;
        return ;
    }
    else
    {
        this->_energyPoints -= 5;
        cout << "ScavTrap " << this->getName() << " attacks " << target << ",";
        cout << " causing : " << this->_attackDamage << " points of damage!" << endl;
        cout << "\n\tNow " << this->getName() << " has " << this->_energyPoints << " energy points left." << endl;
    }
}