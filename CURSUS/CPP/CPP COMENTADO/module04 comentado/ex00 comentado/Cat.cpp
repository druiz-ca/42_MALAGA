/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:18:49 by daniel            #+#    #+#             */
/*   Updated: 2025/02/13 19:26:17 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
// no necesito hacer los using pq las libreria estan enlazadas

Cat::Cat() // no acabo de entender que sea igual a -->  cat::Cat Animal("Cat")
{ 
    this->_type = "Cat";
    cout << "Default Cat constructor" << endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    *this = copy;
    cout << "Copy Cat constructor" << endl;
}

Cat::~Cat()
{
    cout << "Cat destructor is called" << endl;
}

void Cat::makeSound() const
{
    cout << "miau" << endl;
}