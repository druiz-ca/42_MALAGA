/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:59:46 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/01/21 17:46:34 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* 
    Cuando se desarrolla un método fuera de la clase se tiene que poner 
    delante la clase (Zombie::), si se hace dentro de la misma clase
    no hace falta.
*/

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

// aunque haya hecho el const. con parámetro, no se usa
Zombie::Zombie(std::string name)
{
    std::cout << name << " has been created." << std::endl;
}

Zombie::Zombie(void)
{
    // static para que no se reinicie el valor de i cada vez que se 
    // llame al constructor
    static int i = 1;
    
    std::cout << i++ << "º Zombie has been created." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;  
    // this se usa para acceder a las variables de la clase 
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
