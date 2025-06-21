/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:49:16 by daniel            #+#    #+#             */
/*   Updated: 2025/01/23 18:02:11 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*  
Esto da error porque no se puede inicializar un atributo de una clase
en la lista de inicialización de un constructor si el atributo no es
un puntero o una referencia. En este caso, weapon es un objeto de la
clase Weapon, por lo que no se puede inicializar en la lista de inicialización
del constructor.

HumanA::HumanA(std::string name, Weapon &weapon)
{
    this->name = name;
    this->weapon = weapon;
}
*/
//de esta forma se inicializa el atributo weapon en la lista de inicialización
//antes de que se ejecute el cuerpo del constructor
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
    std::cout << "HumanA " << this->name << " has been created with " << this->weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << "HumanA " << this->name << " has been destroyed" << std::endl; 
}

void HumanA::attack(void)
{   // se puede poner cada << en una línea diferente
    std::cout << this->name 
              << " attacks with his " 
              << this->weapon.getType() 
              << std::endl;
}


