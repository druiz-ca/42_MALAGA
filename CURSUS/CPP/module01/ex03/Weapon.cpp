/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:49:09 by daniel            #+#    #+#             */
/*   Updated: 2025/02/15 13:45:56 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
{
    setType(weaponType);
}

Weapon::~Weapon()
{
    return ;
}
std::string const &Weapon::getType()
{
    return (this->type);
}

void Weapon::setType(std::string weaponType)
{
    this->type = weaponType;
}