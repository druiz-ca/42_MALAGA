/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:54:10 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/02/23 11:38:48 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using std::cout;
using std::endl;

const int Fixed::_fract_bits = 8;
// se inicializa la variable de clase _fract_bits con el valor 8

Fixed::Fixed()
{
    this->_fp_value = 0;
    cout << "Default constructor called" << endl;  
}
    /* LA OTRA FORMA DE HACERLO :
    Fixed::Fixed() : _fp_value(0) // en vez = 0 es (0) !!!
    {
        //std::cout << "Default constructor called" << std::endl;
    }*/

Fixed::Fixed(const int value)
{
    // primero se convierte el valor int a un valor de punto fijo (fixed point)
    // << hace esto desplazando el valor a la izquierda por el número de bits fraccionarios ???
    // en fract_bit lo que se hace es multiplicar el valor por 2^8
    // el this hace referencia al objeto actual es decir al objeto que se está creando que en este caso es Fixed
    // en fract_bits se guarda el valor 8
    // se desplaza el valor a la izquierda por 8 bits
    // se guarda el valor en _fp_value
    // en value se guarda el valor que se pasa como argumento que en este caso es 5
    this->_fp_value = value << this->_fract_bits;
    cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float input)
{
    // primero se convierte el valor float a un valor de punto fijo (fixed point)
    // se hace esto multiplicando el valor float por 2^fract_bits
    // en este caso es 2^8 = 256, y después multiplicado por input  
    // ex: 2.5 * 256 = 640
    this->_fp_value = roundf(input * (1 << this->_fract_bits));
    cout << "Float constructor called" << endl;
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
    cout << "Copy constructor called" << endl;
}

Fixed::~Fixed()
{
    cout << "Destructor called" << endl;
}

bool Fixed::operator<(Fixed fixed) const
{
    return (this->_fp_value < fixed.getRawBits());
    
    // se compara el valor de punto fijo del objeto actual con el valor de punto fijo del objeto pasado como argumento
    // lo que devuelve es el valor de la comparación que por ejemplo puede ser true o false
}

bool Fixed::operator>(Fixed fixed) const // revisar
{
    return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator>=(Fixed fixed) const
{
    return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(Fixed fixed) const
{
    return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(Fixed fixed) const
{
    return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(Fixed fixed) const
{
    return (this->toFloat() != fixed.toFloat());
}

// math

Fixed Fixed::operator+(Fixed fixed) const
{
    Fixed result;

    result.setRawBits(this->getRawBits() + fixed.getRawBits());
    return (result);
}

Fixed Fixed::operator-(Fixed fixed) const
{
    Fixed result;

    result.setRawBits(this->getRawBits() - fixed.getRawBits());
    return (result);
}

Fixed Fixed::operator*(Fixed fixed) const
{
    Fixed result;

    result.setRawBits(this->getRawBits() * fixed.getRawBits());
    result.setRawBits(result.getRawBits() >> this->_fract_bits);
    return (result);
}

Fixed Fixed::operator/(Fixed fixed) const
{
    Fixed result;

    result.setRawBits((this->getRawBits() << this->_fract_bits) / fixed.getRawBits());
    // primero se desplaza el valor de punto fijo del objeto actual a la izquierda por el número de bits fraccionarios que en este caso es 8
    // después se divide el valor de punto fijo del objeto actual por el valor de punto fijo del objeto pasado como argumento que en este caso es fixed
    // se desplaza el valor de punto fijo del objeto actual a la izquierda por el número de bits fraccionarios
    // se divide el valor de punto fijo del objeto actual por el valor de punto fijo del objeto pasado como argumento
    result.setRawBits(result.getRawBits());
    return (result);
}

// increment/decrement

Fixed Fixed::operator++(void)
{ // no recibe nada como parametro porque con this ya accede al objeto actual
    this->_fp_value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this); // se crea una copia de this ( del objeto actual)

    operator++(); // se llama al operador de incremento
    return (tmp);
}

Fixed Fixed::operator--(void)
{
    this->_fp_value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);

    operator--();
    return (tmp);
}

float Fixed::toFloat(void) const
{
    return ((float)this->_fp_value / (float)(1 << this->_fract_bits));
}

int Fixed::toInt(void) const
{
    return (this->_fp_value >> this->_fract_bits);
}

int Fixed::getRawBits(void) const
{
    return this->_fp_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_fp_value = raw;
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
    if (first.toFloat() <= second.toFloat())
        return (first);
    else
        return (second);
}

const Fixed &Fixed::min(Fixed const &first, Fixed const &second)
{
    if (first.toFloat() <= second.toFloat())
        return (first);
    else
        return (second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
    if (first.toFloat() >= second.toFloat())
        return (first);
    else
        return (second);
}

const Fixed &Fixed::max(Fixed const &first, Fixed const &second)
{
    if (first.toFloat() >= second.toFloat())
        return (first);
    else
        return (second);
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
    out << value.toFloat();
    // value.toFloat() convierte el valor de punto fijo a un valor float
    // << se usa para imprimir el valor float
    // en out se guarda el valor float
    // en vez de asignarlo con = se usa << porque es un ostream y no se puede asignar con =
    return (out);
}