/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:01:59 by daniel            #+#    #+#             */
/*   Updated: 2025/03/02 12:00:09 by druiz-ca         ###   ########.fr       */
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

//COMO LA FUNCION ES VIRTUAL PURA YA NO SE NECESITA IMPLEMENTAR EN LA CLASE BASE ABSRACTA
/* void Animal::makeSound() const 
{
    cout << "Animal sound" << endl;
} */