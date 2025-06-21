/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:15:03 by daniel            #+#    #+#             */
/*   Updated: 2025/01/29 20:27:45 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//constructor por defecto
Fixed::Fixed() : _fp_value(0)
{
    std::cout << "Default constructor called" << std::endl;
    //cuando se pone : es apra inicializar las variables 
    // en la misma línea que se declara el constructor
    // y se hace poniendo el valor entre paréntesis
}

// constructor por copia
Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    // se llama al método setRawBits para copiar el valor de copy en _fp_value
    this->setRawBits(copy.getRawBits());
    //este constructor se llama cuando se crea un objeto a partir de otro
}

// destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// sobrecarga del operador de asignación
Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy Assignation operator called" << std::endl;
    // se llama al método setRawBits para copiar el valor de copy en _fp_value
    this->setRawBits(copy.getRawBits());
    return (*this);
    // este método se llama cuando se asigna un objeto a otro
}

// método que devuelve el valor en punto fijo
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fp_value);
}

// método que establece el valor en punto fijo
void Fixed::setRawBits(int const raw)
{
    _fp_value = raw;
}