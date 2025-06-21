/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:22:26 by daniel            #+#    #+#             */
/*   Updated: 2025/01/29 18:37:26 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl; 
}

void Harl::info(void)
{
    std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming here for years whereas you started working here last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string type)
{
    // Harl::*ptrtype -> lleva harl porque es un array que va a contener punteros a funciones de la clase Harl
    // porque ptrtype tiene qu ser de tipo Harl??
    // se guarda la direccion de memoria de las funciones de la clase Harl
    void (Harl::*ptrtype[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string types[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (types[i] == type)
            (this->*ptrtype[i])();
            /* como ptrtype lo he declarado de tipo Harl, ahora para acceder
            a las funciones de la clase Harl tengo que usar this->*ptrtype[i] 
            aunque ptrtype no este dentro de la clase Harl!!
            */
    }
}

/*
&Harl::debug -> dirección de memoria de la función debug de la clase Harl
*/