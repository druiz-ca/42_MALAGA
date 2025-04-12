/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:41:38 by daniel            #+#    #+#             */
/*   Updated: 2025/02/23 12:02:32 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap Brian("Brian");

    Brian.setAttackDamage(2);
    Brian.attack("Joseph");
    Brian.attack("John");

    std::cout << std::endl;
    Brian.takeDamage(4);
    Brian.takeDamage(4);

    Brian.beRepaired(10);
    std::cout << std::endl;

    Brian.attack("Peter");
    Brian.attack("Paul");
    Brian.attack("Mary");
    Brian.attack("Lucy");
}