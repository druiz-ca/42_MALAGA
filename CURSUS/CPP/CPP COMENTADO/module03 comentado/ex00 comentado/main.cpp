/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:41:38 by daniel            #+#    #+#             */
/*   Updated: 2025/02/05 18:18:03 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
// clap trap = trampa de aplausos
int main()
{
    ClapTrap Brian("Brian");

    Brian.setAttackDamage(2);
    std::cout << "\n* * * * * Brian is ready to perform! * * * * *\n" << std::endl;
    std::cout << "Hit Points    : " << Brian.getHitPoints() << std::endl;
    std::cout << "Energy Points : " << Brian.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage : " << Brian.getAttackDamage() << std::endl;
    std::cout << "\nStatus        : OK" << std::endl;

    std::cout << "\n* * * * * *  Brian's show begins   * * * * * *\n" << std::endl;
    Brian.attack("Joseph");
    Brian.attack("John");

    std::cout << std::endl;
    Brian.takeDamage(4);
    Brian.takeDamage(4);

    Brian.beRepaired(10);
    std::cout << std::endl; // sirve para hacer un salto de línea

    Brian.attack("Peter");
    Brian.attack("Paul");
    Brian.attack("Mary");
    Brian.attack("Lucy");

    std::cout << "\n* * * * * * * Brian's show ends  * * * * * * *\n" << std::endl;
}