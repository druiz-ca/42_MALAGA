/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:29:35 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/02/22 11:15:23 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
}

Fixed::Fixed(const float inFloat)
{
    cout << "Float constructor called" << endl;
    this->value = roundf(inFloat * (1 << Fixed::bits));
}

Fixed::Fixed(const Fixed &tocopy)
{
    cout << "Copy constructor called" << endl;
    *this = tocopy;
}

Fixed &Fixed::operator=(const Fixed &original)
{
    cout << "Assignation operator called" << endl;
    this->setRawBits(original.getRawBits());
    return *this;
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
    return (float)this->value / (1 << Fixed::bits);
}

int Fixed::toInt(void) const
{
    return this->value >> Fixed::bits;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr)
{
    stream << nbr.toFloat();
    return stream;
}