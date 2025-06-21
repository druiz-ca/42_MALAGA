/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:17:35 by daniel            #+#    #+#             */
/*   Updated: 2025/02/28 13:44:57 by daniel           ###   ########.fr       */
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
    cout << "WrongAnimal copy constructor is called" << endl;
}

// constructor por tipo
WrongAnimal::WrongAnimal(const string &type)
{
    this->_type = type;
    cout << "Wrong Animal type constructor is called" << endl;
}

WrongAnimal::~WrongAnimal()
{
    cout << "Wrong Animal destructor is called" << endl;
}

// recordad que el valor que retorna sigue llevando & !!
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy)
{
    if (this != &copy)
        this->_type = copy._type; // repasar!!!! pq solo se asigna el tipo???
    return (*this);
}

const string& WrongAnimal::getType() const
{
    return(_type);
}

// recordar que los valores se pasan por referencia para no hacer copias de todo
void WrongAnimal::setType(const string &type)
{
    this->_type = type;
}

void WrongAnimal::makeSound() const
{
    cout << "WrongAnimal sound" << endl;    
}