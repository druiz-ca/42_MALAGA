/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:15:38 by daniel            #+#    #+#             */
/*   Updated: 2025/02/02 14:12:34 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream> 

class Fixed
{
    public:
        Fixed(); 
        Fixed(const Fixed& copy); 
        ~Fixed(); 
        Fixed& operator=(const Fixed& copy); 
        int getRawBits(void) const;         
        void setRawBits(int const raw); 
        
    private:
        int                 _fp_value; 
        static const int    _fract_bits; 
    
};

#endif