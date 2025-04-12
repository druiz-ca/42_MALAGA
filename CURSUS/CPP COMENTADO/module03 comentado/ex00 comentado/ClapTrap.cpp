/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:57:49 by daniel            #+#    #+#             */
/*   Updated: 2025/02/06 20:18:41 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// metodo que se llama cuando se crea un objeto de forma automática
ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

// metodo que se llama cuando se crea un objeto con parámetros
ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap parameterized constructor called, and named: " << name << std::endl;
    this->_name = name; // realmente this solo es necesairo si hay ambigüedad (name = name)
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

// metodo que se llama cuando se crea un objeto con otro objeto
ClapTrap::ClapTrap(const ClapTrap &newCT)
{
    std::cout << "ClapTrap copy constructor called, and cloned " << newCT.getName() << std::endl;
    *this = newCT;
    // this es un puntero al objeto ClapTrap que llama al método
}

// metodo que se llama cuando se destruye un objeto
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called, and destroyed: " << _name << std::endl;
}

// metodo que se llama cuando se asigna un objeto a otro
ClapTrap &ClapTrap::operator=(const ClapTrap &newCT)
{
    std::cout << "ClapTrap assignment operator called, and assigned: " << newCT.getName() << std::endl;
    _name = newCT.getName();
    _hitPoints = newCT.getHitPoints();
    _energyPoints = newCT.getEnergyPoints();
    _attackDamage = newCT.getAttackDamage();
    return *this; // devuelve el objeto que llama al método
    // se pone *this porque es un puntero al objeto que llama al método
}

// metodos get y set
const std::string &ClapTrap::getName() const
{
    return _name;
}

unsigned int ClapTrap::getHitPoints() const
{
    return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return _attackDamage;
}

void ClapTrap::setName(const std::string &name)
{
    this->_name = name; // ambigüedad, se pone this para aclarar
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
    this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
    this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
    this->_attackDamage = attackDamage;
}

// metodo que se llama cuando un objeto recibe daño
void ClapTrap::takeDamage(unsigned int amount)
{
    // si la cantidad de daño es mayor que los puntos de vida
    if (amount > _hitPoints)
    {
        std::cout << "ClapTrap " << _name << " takes " << _hitPoints << " points of damage!" << std::endl;
        _hitPoints = 0; // se ponen a 0 los puntos de vida
    }
    else
    { // si la cantidad de daño es menor que los puntos de vida
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
        _hitPoints -= amount; // se restan los puntos de daño a los puntos de vida
    }
}

// metodo que se llama cuando un objeto ataca a otro
void ClapTrap::attack(std::string const &target)
{
    if (_energyPoints < 2) // si los puntos de energía son menores que 2
    {
        std::cout << "ClapTrap " << _name << " is trying to attack " << target << ", but is out of energy points!" << std::endl;
        return;
    }
    else if (_hitPoints <= 0) // si los puntos de vida son menores o iguales a 0
    {
        std::cout << "ClapTrap " << _name << " is trying to attack " << target << ", but is out of hit points... is dead!" << std::endl;
        return;
    }
    else // si los puntos de energía son mayores o iguales a 2
    {
        _energyPoints -= 2; // restamos 2 puntos de energía porque atacamos
        std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
    }
}

// metodo que se llama cuando un objeto se repara
void ClapTrap::beRepaired(unsigned int amount)
{
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " has been repaired for " << amount << " points!" << std::endl;
}