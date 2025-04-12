/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:18:28 by daniel            #+#    #+#             */
/*   Updated: 2025/02/28 13:44:32 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    this->_type = "Dog";
    cout << "dog Default constructor" << endl;   
}

Dog::Dog(const Dog &) : Animal("Dog")
{
    cout << "Dog copy constructor is called" << endl;
}

Dog::~Dog()
{
    cout << "Dog destructor is called" << endl;
}

void Dog::makeSound() const
{
    cout << "guau" << endl;
}