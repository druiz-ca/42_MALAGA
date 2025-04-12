/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:15:29 by daniel            #+#    #+#             */
/*   Updated: 2025/02/23 13:07:20 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp" 

using std::cout;
using std::endl;

int main()
{
    FragTrap FragTrap_aux("Player");
    FragTrap FragTrap("ScavTrap");

    FragTrap_aux.setEnergyPoints(50);
    FragTrap = FragTrap_aux; 

    FragTrap.attack("pepe");
    cout << endl;

    FragTrap.takeDamage(4);
    FragTrap.beRepaired(4);
    FragTrap.highFiveGuys();

    cout << endl;

    FragTrap.attack("luis");
    cout << endl;

}