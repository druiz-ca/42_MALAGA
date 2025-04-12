/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:49:19 by daniel            #+#    #+#             */
/*   Updated: 2025/01/23 18:00:50 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void attack(void);
    private:
        std::string name;
        Weapon &weapon;
};

#endif

/*
- clase HumanA:
    - atributos privados: name, weapon
    - función miembro: atack() que muestra: 
        name + " attacks with his " + weapon type
*/