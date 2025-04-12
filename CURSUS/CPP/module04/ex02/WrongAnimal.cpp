/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:17:35 by daniel            #+#    #+#             */
/*   Updated: 2025/02/13 21:03:42 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    cout << "WrongAnimal default constructor" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    *this = copy;
    cout << "cpoy constructor is called" << endl;
}

WrongAnimal::WrongAnimal(const string &type)
{
    this->_type = type;
    cout << "type constructor is called" << endl;
}

WrongAnimal::~WrongAnimal()
{
    cout << "destructor is called" << endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy)
{
    if (this != &copy)
        this->_type = copy._type;
    return (*this);
}

const string& WrongAnimal::getType() const
{
    return(_type);
}

void WrongAnimal::setType(const string &type)
{
    this->_type = type;
}

void WrongAnimal::makeSound() const
{
    cout << "WrongAnimal sound" << endl;    
}