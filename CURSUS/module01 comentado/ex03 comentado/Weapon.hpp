/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:47:52 by daniel            #+#    #+#             */
/*   Updated: 2025/01/23 17:43:54 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    public:
    //los const. y dest. se llaman igual que la clase siempre
    // solo los const. y dest. no tienen tipo de retorno
        Weapon(std::string weaponType); //Constructor con argumento
        ~Weapon(); //Destructor
        const std::string &getType();
        void setType(std::string weaponType);

    private:
        std::string type;
};


#endif
/*
- clase Weapon:
    - atributo privado: type
    - funcion miembro:
        - getType: devuelve referencia constante a type
        - setType: establece type usando el nuevo argumento pasado
        
*/