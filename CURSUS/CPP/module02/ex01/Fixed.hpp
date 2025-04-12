/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:29:45 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/02/15 14:14:43 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream> 
#include <cmath> 
#include <cstdlib> 


class Fixed
{
    public:
        Fixed(void);                             
        Fixed(const int inInt);                    
        Fixed(const float inFloat);                 
        Fixed(const Fixed &tocopy);               
        Fixed &operator=(const Fixed &original);
        ~Fixed(void);                              
    
        int getRawBits(void) const;                
        void setRawBits(int const raw);             
        
        float toFloat(void) const;                  
        int toInt(void) const;                     

    private:
        int value;                                
        static const int bits = 8;                  
};

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);    
#endif
