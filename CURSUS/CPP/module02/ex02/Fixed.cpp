/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:54:10 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/02/23 11:19:26 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using std::cout;
using std::endl;

const int Fixed::_fract_bits = 8;

Fixed::Fixed()
{
    this->_fp_value = 0;
    cout << "Default constructor called" << endl;  
}

Fixed::Fixed(const int value)
{
    this->_fp_value = value << this->_fract_bits;
    cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float input)
{
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
    result.setRawBits(result.getRawBits());
    return (result);
}

// increment/decrement

Fixed Fixed::operator++(void)
{
    this->_fp_value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this); 

    operator++();
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
    return (out);
}