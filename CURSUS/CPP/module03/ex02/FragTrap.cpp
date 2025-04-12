/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:17:41 by daniel            #+#    #+#             */
/*   Updated: 2025/02/11 21:28:43 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

using std::cout;
using std::string;
using std::endl;

FragTrap::FragTrap()
{
    cout << "FragTrap default constructor" << endl;    
}

FragTrap::FragTrap(const string &name)
{
    this->_name = name;
    cout << "FragTrap name constructor" << endl;
}

FragTrap::FragTrap(const FragTrap &newFragTrap)
{
    *this = newFragTrap;
    cout << "FragTrap copy constructor" << endl;
}

FragTrap::~FragTrap()
{
    cout << "FragTrap destructor" << endl;    
}

void FragTrap::highFiveGuys(void) const
{
    cout << "FragTrap " << this->_name << " says: Give me five!" << endl;
}