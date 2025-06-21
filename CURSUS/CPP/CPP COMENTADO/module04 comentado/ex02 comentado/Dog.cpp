/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:18:28 by daniel            #+#    #+#             */
/*   Updated: 2025/03/01 12:55:18 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->_type = "Dog";
    this->_brain = new Brain;
    for (int i = 0; i < 100; i++)
        this->_brain->setIdea("new ideas", i);
    cout << "Dog Default constructor" << endl;   
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    this->_brain = new Brain(*copy._brain);
    this->_type = copy._type;
    cout << "Dog copy constructor is called" << endl;
}

Dog::~Dog()
{
    // el brain se tiene que borrar en el destructor de la clase que lo crea
    delete this->_brain;
    cout << "Dog destructor is called" << endl;
}

Dog &Dog::operator=(Dog const &copy)
{
    if (this != &copy)
    {
        Animal::operator=(copy);
        delete(this->_brain);
        this->_brain = new Brain(*copy._brain);
        this->_type = copy._type;
    }
    return (*this);
}

void Dog::makeSound() const
{
    cout << "guau" << endl;
}

void Dog::buildDogIdeas(std::string const &idea, int const i)
{
    this->_brain->setIdea(idea, i);
}

void Dog::getDogIdeas(int const index)
{
    cout << this->_brain->getIdea(index) << endl;
}

Brain *Dog::getBrain() const
{
    return this->_brain; 
}