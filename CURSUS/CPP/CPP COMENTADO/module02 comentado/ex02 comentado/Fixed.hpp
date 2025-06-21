/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:54:29 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/02/23 10:58:58 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(int const value); // const para que no se pueda modificar el valor
        Fixed(float const value);
        Fixed(const Fixed &copy);
        ~Fixed();

        bool operator<(Fixed fixed)const; 
        //el const al final de la funcion indica que no se va a modificar el objeto
        bool operator>(Fixed fixed)const;
        bool operator>=(Fixed fixed)const;
        bool operator<=(Fixed fixed)const;
        bool operator==(Fixed fixed)const;
        bool operator!=(Fixed fixed)const;

        Fixed operator+(Fixed fixed)const;
        Fixed operator-(Fixed fixed)const;
        Fixed operator*(Fixed fixed)const;
        Fixed operator/(Fixed fixed)const;

        Fixed operator++(void);
        Fixed operator++(int);
        Fixed operator--(void);
        Fixed operator--(int);

        float toFloat(void)const;
        int toInt(void)const;
        
        // static para que no se pueda modificar el objeto
        static Fixed &min(Fixed &first, Fixed &second);
        // const para que no se pueda modificar el objeto
        static const Fixed &min(Fixed const &first, Fixed const &second);
        static Fixed &max(Fixed &first, Fixed &second);
        static const Fixed &max(Fixed const &first, const Fixed &second);
        
        int getRawBits(void)const;
        void setRawBits(int const raw);
    
    private:
        int _fp_value; // los_ se usan para indicar que es un atributo privado
		static const int _fract_bits;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);
// esto va fuera de la clase 