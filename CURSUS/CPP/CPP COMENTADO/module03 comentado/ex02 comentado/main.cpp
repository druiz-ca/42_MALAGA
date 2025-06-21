/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:15:29 by daniel            #+#    #+#             */
/*   Updated: 2025/02/11 21:25:33 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp" // ahora el main tiene que estar enlazado al FRAGTRAP!!!

using std::cout;
using std::endl;

int main()
{
    FragTrap FragTrap_aux("Player");
    FragTrap FragTrap("ScavTrap");

    FragTrap_aux.setEnergyPoints(50);
    FragTrap = FragTrap_aux; // se copian los valores de ScavTrap1 a ScavTrap2

    cout << "\n------------ FragTrap status ------------" << endl;
    cout << "\tAttack damage: " << FragTrap.getDamagePoints() << endl;
    cout << "\tEnergy points: " << FragTrap.getEnergyPoints() << endl;
    cout << "\tHit points   : " << FragTrap.getHitPoints() << endl;

    cout << "\n------------ Start game ------------ " << endl;

    FragTrap.attack("pepe");
    cout << endl;

    FragTrap.takeDamage(4);
    FragTrap.beRepaired(4);
    FragTrap.highFiveGuys();

    cout << endl;

    FragTrap.attack("luis");
    cout << endl;

}
/*
- cambia los mensajes de los constructores y destructores de las clases
- cuando se crea un fragtrap se construye un claptrap
- metodo nuevo:     void highFivesGuys(void);
    muestra: una solicitud positiva de choca esos cinco
*/