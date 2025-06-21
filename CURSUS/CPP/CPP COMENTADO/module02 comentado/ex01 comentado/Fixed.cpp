/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:29:35 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/02/22 13:41:29 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// para evitar tener que poner std::
using std::cout;
using std::endl;

Fixed::Fixed(void)
{
    cout << "Default constructor called" << endl;
    this->value = 0;
}

Fixed::Fixed(const int inInt)
{
    cout << "Int constructor called" << endl;
    this->value = inInt << Fixed::bits;
    // se neceista poner Fixed::bits porque bits es una variable de clase
    // << lo uqe hace es mover los bits del entero inInt a la izquierda tantas veces como bits tenga la variable Fixed::bits
    // es decir, inInt * 2^8 = inInt * 256
}

Fixed::Fixed(const float inFloat)
{
    cout << "Float constructor called" << endl;
    this->value = roundf(inFloat * (1 << Fixed::bits));
    // roundf es una funcion de la libreria math.h que redondea un float a un entero
    //1 << Fixed::bits lo que hace es mover el 1 bits veces a la izquierda, es decir, 1 * 2^8 = 256
    // << es un operador de desplazamiento a la izquierda 
}

Fixed::Fixed(const Fixed &tocopy)
{
    cout << "Copy constructor called" << endl;
    *this = tocopy;
    // el *this es un puntero al objeto actual
}

Fixed &Fixed::operator=(const Fixed &original)
{
    cout << "Assignation operator called" << endl;
    this->setRawBits(original.getRawBits());
    return *this;
    // devuelve una referencia al objeto actual
    // se pasa por referencia para no hacer una copia del objeto
    // se pasa const para que no se pueda modificar el objeto que se asigna
    //operator lleva Fixed:: porque es una función de la clase Fixed
}

Fixed::~Fixed(void)
{
    cout << "Destructor called" << endl;
}

int Fixed::getRawBits(void) const
{
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    // se hace un cast a float porque el resultado es un float
    return (float)this->value / (1 << Fixed::bits); // al ser bits es un num 1 que se despaza a la izquierda 8 veces
    // 1 << Fixed::bits lo que hace es mover el 1 bits(8) veces a la izquierda, es decir, 1 * 2^8 = 256 ( 2*2*2*2....8 veces = 256)
    // << es un operador de desplazamiento a la izquierda
    // se divide entre 256 para obtener el valor en float
}

int Fixed::toInt(void) const
{
    return this->value >> Fixed::bits;
}

// sobrecarga del operador de inserción para imprimir un objeto de la clase Fixed
    // solo se usa cuando el prog detecta que se usa << seguido de un objeto de la clase Fixed sino usa el << normal !!!!
std::ostream &operator<<(std::ostream &stream, const Fixed &nbr) // se construye otro objeto Fixed con el valor de nbr
{ // ostrem es una clase de la librería iostream que se usa para imprimir en pantalla
    stream << nbr.toFloat(); // es nbr.tofloat porque nbr es una referencia a un objeto de la clase Fixed no solo un numero
    return stream;

    // ostream es una clase de la librería iostream que se usa para imprimir en pantalla
    // devuelve un objeto de la clase ostream
    // esta funcion se llama cuando se usa el operador << con un objeto de la clase Fixed
}