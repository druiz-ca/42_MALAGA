/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:18:49 by daniel            #+#    #+#             */
/*   Updated: 2025/03/01 13:53:17 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
// no necesito hacer los using pq las libreria estan enlazadas

Cat::Cat() : Animal()// no acabo de entender que sea igual a -->  cat::Cat Animal("Cat")
{ 
    this->_brain = new Brain();
    this->_type = "Cat";
    for (int i = 0; i < 100; i++)
        buildCatIdeas("new ideas", i);
    cout << "Default Cat constructor" << endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    this->_brain = new Brain();
    this->_type = copy._type;
    cout << "Copy Cat constructor" << endl;
}

Cat::~Cat()
{
    delete this->_brain;
    //se hace delete aqui pq es el constructor de la clase
    cout << "Cat destructor is called" << endl;
}

Cat &Cat::operator=(Cat const &copy)
{
    if (this != &copy)
    {
        Animal::operator=(copy);
        delete(this->_brain);
        // para liberar la memoria que se reservó en el constructor
        // para que en la nueva asignación no haya fugas de memoria
        this->_brain = new Brain(*copy._brain);
        this->_type = copy._type;
    }
    return (*this);
}

void Cat::buildCatIdeas(std::string const &idea, int const i)
{
    this->_brain->setIdea(idea, i);
}

void Cat::getCatIdeas(int const index)
{
    cout << this->_brain->getIdea(index) << endl;
}

void Cat::makeSound() const
{
    cout << "miau" << endl;
}

Brain *Cat::getBrain() const
{
    return this->_brain;
}