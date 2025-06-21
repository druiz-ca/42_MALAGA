/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:20:50 by daniel            #+#    #+#             */
/*   Updated: 2025/02/09 19:13:04 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using std::cout;
using std::endl;

int main()
{ // no se cra ningun objeto de la clase ClapTrap (base) porque la clase derivada
    // llama al constructor de la clase base y se inicializan los valores de la 
    // clase base 
    ScavTrap ScavTrap_aux("Player");
    ScavTrap ScavTrap("ScavTrap");

    ScavTrap_aux.setEnergyPoints(50);
    ScavTrap = ScavTrap_aux; // se copian los valores de ScavTrap1 a ScavTrap2

    cout << "\n------------ ScavTrap status ------------" << endl;
    cout << "\tAttack damage: " << ScavTrap.getAttackDamage() << endl;
    cout << "\tEnergy points: " << ScavTrap.getEnergyPoints() << endl;
    cout << "\tHit points   : " << ScavTrap.getHitPoints() << endl;

    cout << "\n------------ Start game ------------ " << endl;

    ScavTrap.attack("pepe");
    cout << endl;

    ScavTrap.takeDamage(4);
    ScavTrap.beRepaired(4);

    cout << endl;

    ScavTrap.attack("luis");
    cout << endl;

    ScavTrap.guardGate();    // metodo de la clase derivada ScavTrap
        // solo para mostrar que esta en modo guardia
}