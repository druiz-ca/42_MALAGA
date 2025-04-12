/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:01:59 by daniel            #+#    #+#             */
/*   Updated: 2025/03/02 11:58:22 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal()
{
    this->_type = "Animal";
    cout << "Animal Constructor default is called" << endl;
}

Animal::Animal(Animal const &copyAnimal)
{
    cout << "Animal Copy constructor is called" << endl;
    this->_type = copyAnimal._type;
}

Animal::~Animal()
{
    cout << "Animal destructor is called" << endl;
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
