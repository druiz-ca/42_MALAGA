/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:21:59 by daniel            #+#    #+#             */
/*   Updated: 2025/02/15 14:21:06 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::endl;
using std::string;
using std::cin;

ClapTrap::ClapTrap()
{
    cout << "ClapTrap default constructor called" << endl;
    this-> _attackDamage = 20;
    this-> _energyPoints = 50; 
    this-> _hitPoints = 100;
}

ClapTrap::ClapTrap(string name)
{
    cout << "ClapTrap parameterized constructor called, and named: " << name << endl;
    this-> _name = name; 
    this-> _attackDamage = 20; 
    this-> _energyPoints = 50; 
    this-> _hitPoints = 100; 
}

ClapTrap::ClapTrap(const ClapTrap &copyClapTrap)
{
    cout << "ClapTrap copy constructor called, and cloned " << copyClapTrap.getName() << endl;
    *this = copyClapTrap;
}

ClapTrap::~ClapTrap()
{
    cout << "ClapTrap destructor called, and destroyed: " << this->_name << endl;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &copyClapTrap)
{
    cout << "ClapTrap assignment operator called, and assigned: " << copyClapTrap.getName() << endl;
    
    this-> setName(copyClapTrap.getName());
    this-> setAttackDamage(copyClapTrap.getAttackDamage());
    this-> setEnergyPoints(copyClapTrap.getEnergyPoints());
    this-> setHitPoints(copyClapTrap.getHitPoints());
    return *this;
}

const string& ClapTrap::getName() const 
{
    return (this->_name);
}

unsigned int ClapTrap::getHitPoints() const
{
    return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return (this->_energyPoints);
}

unsigned int ClapTrap::getAttackDamage() const
{
    return (this->_attackDamage);
}

void ClapTrap::setName(const string &name)
{
    this->_name = name;
}

void ClapTrap::setHitPoints(unsigned int num)
{
    this->_hitPoints = num;
}

void ClapTrap::setEnergyPoints(unsigned int num)
{
    this->_energyPoints = num;
}

void ClapTrap::setAttackDamage(unsigned int num)
{
    this->_attackDamage = num;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->_hitPoints += amount;
    cout << "ClapTrap " << this->_name << " has been repaired by " << amount << " points!" << endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{  
    if (amount > this->_hitPoints)
    {  
        cout << "ClapTrap " << this->_name << " takes " << this->_hitPoints << " points of damage!" << endl;
        this-> _hitPoints = 0;
    }
    else
    {
        cout << "ClapTrap " << this-> _name << " takes " << amount << " points of damage!" << endl;
        this->_hitPoints -= amount;
    }
}

void ClapTrap::attack(const string &target)
{
    if (this->_energyPoints < 2) 
    {
        cout << "ClapTrap " << this->_name << " is trying to attack " << target << ", but is out of energy points!" << endl;
        return ;
    }
    else if (this-> _hitPoints <= 0) 
    {
        cout << "ClapTrap " << this->_name << " is trying to attack " << target << ", but is out of hit points... is dead!" << endl;
        return ;
    }
    else 
    {
        cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << endl;
        this->_energyPoints -= 2;
    }
}