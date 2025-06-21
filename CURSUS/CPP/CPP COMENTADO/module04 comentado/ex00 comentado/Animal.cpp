/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:01:59 by daniel            #+#    #+#             */
/*   Updated: 2025/02/28 13:44:17 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    cout << "Animal Constructor default is called" << endl;
}

Animal::Animal(Animal const &copyAnimal)
{
    cout << "Animal Copy constructor is called" << endl;
    *this = copyAnimal;
}

Animal::~Animal()
{
    cout << "Animal destructor is called" << endl;
}

Animal::Animal(const string &type) : _type(type) // repasar!!!!
{
    cout << "Animal Type Constructor is called" << endl;
}

// cuando se desarrolla el método, operator ya no necesita el &
// pero los parámetros que recibe y retorna si ( no con *)
Animal& Animal::operator=(const Animal &copyAnimal)
{//this es un puntero implicito que apunta a la direccion de memoria del objeto
    if (this != &copyAnimal)
        this->_type = copyAnimal._type; // con "." pq es por referencia
    return (*this);
} // ENTONCES SOLO ASIGNA EL TIPO?? O SE LLAMA AL CONSTRUCTOR POR MANDAR EL TYPO..

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