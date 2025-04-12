/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:15:38 by daniel            #+#    #+#             */
/*   Updated: 2025/01/29 20:22:02 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream> // para std::cout

class Fixed
{
    public:
        Fixed(); // constructor por defecto
        // constructor por copia
        Fixed(const Fixed& copy); //pq es const? y pq se pasa por referencia?
        ~Fixed(); // destructor
        
        /*  CONSTRUCTOR DE COPIA PARA CREAR UNA COPIA DE UN OBJETO
        se ejecuta automáticamente cuando se asigna un objeto a otro
        no hace falta llamarlo.
        sirve para copiar los valores de un objeto a otro 
        - se tiene que llamar exactamente así
        - lo de operator= significa justo eso, que es para asignar "="
        */
        Fixed& operator=(const Fixed& copy); // sobrecarga del operador de asignación
        

        
        int getRawBits(void) const; // método que devuelve el valor en punto fijo
        // sirve para acceder a las variables privadas de la clase
        
        void setRawBits(int const raw); // método que establece el valor en punto fijo
        // sirve para modificar las variables privadas de la clase
        
    private:
        int                 _fp_value; // valor en punto fijo
        static const int    _fract_bits; // número de bits fraccionales
    
};

#endif