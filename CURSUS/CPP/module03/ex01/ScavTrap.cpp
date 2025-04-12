/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:22:18 by daniel            #+#    #+#             */
/*   Updated: 2025/02/23 12:34:52 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using std::cout;
using std::endl;
using std::string;

ScavTrap::ScavTrap() : ClapTrap()
{
    cout << "ScavTrap default constructor called" << endl;
}

ScavTrap::ScavTrap(const string &name) : ClapTrap(name)
{
    cout << "ScavTrap " << name << " has been created." << endl;
}
ScavTrap::ScavTrap(const ScavTrap &copyScavTrap) : ClapTrap(copyScavTrap)
{
    cout << "ScavTrap copy constructor called." << endl;
}
ScavTrap::~ScavTrap()
{  
    cout << "ScavTrap " << this->getName() << " has been destroyed." << endl;
}
void ScavTrap::guardGate() const
{
    cout << "ScavTrap " << this->getName() << " has entered in Gate Keeper Mode." << endl;
}

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
        cout << "\nNow " << this->getName() << " has " << this->_energyPoints << " energy points left." << endl;
    }
}