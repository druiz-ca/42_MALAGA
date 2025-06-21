/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:49:11 by daniel            #+#    #+#             */
/*   Updated: 2025/01/23 18:00:24 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void attack(void);
        void setWeapon(Weapon &weapon); // establece el arma
        
    private:
        std::string name;
        Weapon *ptrweapon;  // puntero a la clase Weapon??
};

#endif
/*
- clase HumanB:
    - atributo privado: name, weapon
    - puede no estar armado?
    

*/