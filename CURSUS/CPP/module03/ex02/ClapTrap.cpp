/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:16:30 by daniel            #+#    #+#             */
/*   Updated: 2025/02/23 13:10:23 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::endl;

ClapTrap::ClapTrap()
{
    cout << "default constructor is called" << endl;
    this-> _attackDamage = 30;
    this-> _energyPoints = 50;
    this-> _hitPoints = 100;
}

ClapTrap::ClapTrap(string name)
{
    _name = name;
    cout << "constructor with name is called " << _name << endl;
}

ClapTrap::ClapTrap(ClapTrap &copyClapTrap)
{
    cout << "copy constructor is called" << endl;
    *this = copyClapTrap;
}

ClapTrap::~ClapTrap()
{
    cout << "destructor is called" << endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &copyTrapClap)
{
    this->_name = copyTrapClap._name;
    return *this;
}


/* GETS */
string &ClapTrap::getName()
{
    return (this->_name);
}

unsigned int ClapTrap::getHitPoints()
{
    return (this->_hitPoints);
}

unsigned int ClapTrap::getDamagePoints()
{
    return (this->_attackDamage);
}

unsigned int ClapTrap::getEnergyPoints()
{
    return (this->_energyPoints);
}

/* SETS */
void ClapTrap::setAttackDamage(unsigned int amount)
{
    this->_attackDamage = amount;
}

void ClapTrap::setEnergyPoints(unsigned int amount)
{
    this->_energyPoints = amount;
}

void ClapTrap::setHitPoints(unsigned int amount)
{
    this->_hitPoints = amount;
}

/* METHODS */
void ClapTrap::beRepaired(unsigned int amount)
{
    this->_hitPoints += amount;
    cout << this->_name << " has reapired for " << amount << endl;
}

void ClapTrap::attack(const string &name)
{
    if (this->_energyPoints < 2)
    {
        cout << "ClapTrap " << this->_name << " is tryiing to attack to " << name << " but he don't have energy points!" << endl;
        return ;   
    }
    else if (this->_hitPoints <=0)
    {
        cout << "ClapTrap " << this->_name << " is trying to attack to " << name << " but he is dead!" << endl;
        return ;
    }
    this->_energyPoints -= 2;
    cout << "ClapTrap " << this->_name << "has attack to " << name << " causing "<< this->_attackDamage << " points of damage!"<< endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    cout << "ClapTrap " << this->_name << " has taked " << amount << "points of damage!" << endl;
    this->_attackDamage -= amount;
    if (this->_attackDamage < 0)
    {
        this->_attackDamage = 0;
        cout << "ClapTrap " << this->_name << " has died!" << endl;     
    }
    
}