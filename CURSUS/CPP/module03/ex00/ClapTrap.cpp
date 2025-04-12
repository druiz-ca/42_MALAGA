/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:57:49 by daniel            #+#    #+#             */
/*   Updated: 2025/02/23 12:00:20 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap parameterized constructor called, and named: " << name << std::endl;
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &newCT)
{
    std::cout << "ClapTrap copy constructor called, and cloned " << newCT.getName() << std::endl;
    *this = newCT;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called, and destroyed: " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &newCT)
{
    std::cout << "ClapTrap assignment operator called, and assigned: " << newCT.getName() << std::endl;
    _name = newCT.getName();
    _hitPoints = newCT.getHitPoints();
    _energyPoints = newCT.getEnergyPoints();
    _attackDamage = newCT.getAttackDamage();
    return *this;
}

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
    _name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
    _hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
    _energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
    _attackDamage = attackDamage;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > _hitPoints)
    {
        std::cout << "ClapTrap " << _name << " takes " << _hitPoints << " points of damage!" << std::endl;
        _hitPoints = 0; 
    }
    else
    { 
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
        _hitPoints -= amount;
    }
}

void ClapTrap::attack(std::string const & target)
{
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is trying to attack " << target << ", but is out of energy points!" << std::endl;
        return;
    }
    else if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is trying to attack " << target << ", but is out of hit points... is dead!" << std::endl;
        return;
    }
    else
    {
        _energyPoints -= 1;
        std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " has been repaired for " << amount << " points!" << std::endl;
}