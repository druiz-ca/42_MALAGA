/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:54:29 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/02/23 11:16:15 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(int const value); 
        Fixed(float const value);
        Fixed(const Fixed &copy);
        ~Fixed();

        bool operator<(Fixed fixed)const; 
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
        
        static Fixed &min(Fixed &first, Fixed &second);
        static const Fixed &min(Fixed const &first, Fixed const &second);
        static Fixed &max(Fixed &first, Fixed &second);
        static const Fixed &max(Fixed const &first, const Fixed &second);
        
        int getRawBits(void)const;
        void setRawBits(int const raw);
    
    private:
        int _fp_value;
		static const int _fract_bits;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);
