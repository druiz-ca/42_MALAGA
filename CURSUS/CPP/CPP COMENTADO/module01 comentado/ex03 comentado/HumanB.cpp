/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:49:14 by daniel            #+#    #+#             */
/*   Updated: 2025/01/23 18:02:43 by daniel           ###   ########.fr       */
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
              << (*this->ptrweapon).getType() // !!!! IMPORTANTE
              // para poder acceder a los miembros de un objeto que es apuntado por un puntero
              // primero se tiene que desreferenciar el puntero y luego se usa el operator "." 
              << std::endl ;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->ptrweapon = &weapon;
}
