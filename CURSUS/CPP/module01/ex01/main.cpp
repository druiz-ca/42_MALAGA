/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:54:29 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/01/21 18:01:48 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string num_string;
    int num;

    while (1)
    {
        std::cout << "Enter the number of Zombies: " << std::endl;
        std::cin >> num_string;
        while (checknumber(num_string) == 1)
        {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin >> num_string;
        }
        break;
    }
    std::istringstream iss(num_string);

    if (!(iss >> num))
    {
        std::cerr << "Invalid input: not a valid integer" << std::endl;
        return (1);
    }

    Zombie *horde = zombieHorde(num, "Zombie");

    for (int i = 0; i < num; i++)
    {
        std::cout << i + 1 << "º ";
        horde[i].announce();
    }

    delete[] horde;
    return (0);
}
