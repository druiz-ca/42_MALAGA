/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:49:09 by daniel            #+#    #+#             */
/*   Updated: 2025/01/23 17:33:20 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"


//todos lo métodos de una clase llevan el nombre de la clase delante
// lo que no llevan es el tipo de retorno (el const y el destructor)
Weapon::Weapon(std::string weaponType)
{
    setType(weaponType);
    // se puede usar this->setType(weaponType) si hubiese ambigüedad
}

Weapon::~Weapon()
{
    return ;
}

// cuando el método este dentro de una clase hay que poner el nombre de la clase
std::string const &Weapon::getType()
{
    return (this->type);
}

void Weapon::setType(std::string weaponType)
{
    this->type = weaponType;
}