/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:59:46 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/01/21 18:02:04 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int checknumber(std::string str)
{
    if (str[0] == '\0')
        return (0);
    for (int i = 0; str[i]; i++)
    {
        if (isdigit(str[i]) == 0)
            return (1);
    }
    return(0);
}

Zombie::Zombie(std::string name)
{
    std::cout << name << " has been created." << std::endl;
}

Zombie::Zombie(void)
{
    static int i = 1;
    
    std::cout << i++ << "º Zombie has been created." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;  
}  

void Zombie::putname(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    static int i = 1;
    std::cout << i++ <<"º Zombie: are destroying" << std::endl;
}
