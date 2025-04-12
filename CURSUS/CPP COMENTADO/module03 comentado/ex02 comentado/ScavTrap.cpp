/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:17:09 by daniel            #+#    #+#             */
/*   Updated: 2025/02/11 20:53:04 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using std::string;
using std::cout;
using std::endl;


ScavTrap::ScavTrap()
{
    cout << "ScavTrap default constructor is called" << endl;
}
    /*    OTRA FORMA DE HACERLO:
    ScavTrap::ScavTrap() : ClapTrap() */

ScavTrap::ScavTrap(const string &name)
{
    this->_name = name;
    cout << "ScavTrap name constructor is called" << endl;
}

ScavTrap::ScavTrap(const ScavTrap &newScavTrap)
{
    cout << "ScavTrap copy constructor is called" << endl;
    *this = newScavTrap;
}

void ScavTrap::attack(const string &name) // para que se necesita que sea const??
{
    if (this->_energyPoints < 5)
    {
        cout << "ScavTrap " << this->_name << " has no energy points" << endl;
        return ;
    }
    else
    {
        this->_energyPoints -= 5;       
        cout << "ScavTrap " << this->_name << " attacks " << name;
        cout << " and make it " << this->_attackDamage << endl;
    }
}