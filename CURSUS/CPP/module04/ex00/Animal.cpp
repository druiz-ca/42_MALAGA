/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:01:59 by daniel            #+#    #+#             */
/*   Updated: 2025/02/13 21:02:38 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    cout << "Constructor default is called" << endl;
}

Animal::Animal(Animal const &copyAnimal)
{
    cout << "Copy constructor is called" << endl;
    *this = copyAnimal;
}

Animal::~Animal()
{
    cout << "Animal destructor is called" << endl;
}

Animal::Animal(const string &type) : _type(type) 
{
    cout << "Type Constructor is called" << endl;
}

Animal& Animal::operator=(const Animal &copyAnimal)
{
    if (this != &copyAnimal)
        this->_type = copyAnimal._type; 
    return (*this);
} 

string Animal::getType() const
{
    return (this->_type);
}

void Animal::setType(const string &type)
{
    this->_type = type;
}

void Animal::makeSound() const 
{
    cout << "Animal sound" << endl;
}