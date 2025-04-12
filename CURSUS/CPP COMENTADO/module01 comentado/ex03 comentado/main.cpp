/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:47:11 by daniel            #+#    #+#             */
/*   Updated: 2025/01/23 17:55:48 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{ //hay que poner llaves para que se ejecute el destructor de HumanA
		Weapon armory("crude spiked club"); 
		HumanA pepe("Pepe", armory);
		pepe.attack();
		armory.setType("some other type of club");
		pepe.attack();
	}
	{
		Weapon armory("crude spiked club");
            //también se puede hacer así:
            //Weapon armory = Weapon("crude spiked club");
		HumanB lola("Lola");
		lola.setWeapon(armory);
		lola.attack();
		armory.setType("some other type of club");
		lola.attack();
	}
}
/*
BLOQUES DE LLAVES:
    - Para crear ámbitos locales para que los desrtuctores de los 
    objetos creados dentro de estos bloques se llamen al final del bloque
    de forma automática porque se cierran las llaves.
    
*/