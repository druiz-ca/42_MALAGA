/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:47:11 by daniel            #+#    #+#             */
/*   Updated: 2025/02/19 20:06:10 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon armory("crude spiked club"); 
		HumanA pepe("Pepe", armory);
		pepe.attack();
		armory.setType("some other type of club");
		pepe.attack();
	}
	{
		Weapon armory("crude spiked club");
		HumanB lola("Lola");
		lola.attack();
		lola.setWeapon(armory);
		lola.attack();
		armory.setType("some other type of club");
		lola.attack();
	}
}