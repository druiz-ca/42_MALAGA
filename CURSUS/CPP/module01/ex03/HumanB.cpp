/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:49:14 by daniel            #+#    #+#             */
/*   Updated: 2025/02/15 13:45:29 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    std::cout << "HumanB " << this->name << " has been created without weapon." << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB " << this->name << " has been destroyed." << std::endl;
}

void HumanB::attack(void)
{
    std::cout << this->name
              << " attacks with his "
              << (*this->ptrweapon).getType()
              << std::endl ;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->ptrweapon = &weapon;
}
