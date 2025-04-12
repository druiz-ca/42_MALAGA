/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:20:50 by daniel            #+#    #+#             */
/*   Updated: 2025/02/23 12:34:12 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using std::cout;
using std::endl;

int main()
{
    ScavTrap ScavTrap_aux("Player");
    ScavTrap ScavTrap("ScavTrap");

    ScavTrap_aux.setEnergyPoints(50);
    ScavTrap = ScavTrap_aux; 

    ScavTrap.attack("pepe");
    cout << endl;

    ScavTrap.takeDamage(4);
    ScavTrap.beRepaired(4);

    cout << endl;

    ScavTrap.attack("luis");
    cout << endl;

    ScavTrap.guardGate();   
}