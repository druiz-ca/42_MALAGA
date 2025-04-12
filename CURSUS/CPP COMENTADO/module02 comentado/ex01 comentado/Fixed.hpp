/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:29:45 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/02/02 14:06:15 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream> // para cout, endl
#include <cmath> // para roundf() (redondear un float)
#include <cstdlib> // para NULL


class Fixed
{
    public:
        Fixed(void);                                // Default constructor
        Fixed(const int inInt);                     // Parametric constructor
        Fixed(const float inFloat);                 // Parametric constructor
        Fixed(const Fixed &tocopy);                // Copy constructor
            // consta para que no se pueda modificar el objeto que se copia
            // se pasa por referencia para no hacer una copia del objeto
        Fixed &operator=(const Fixed &original);    // Assignation operator overload
            // sobrecarga del operador de asignación
            // devuelve una referencia a un objeto de la clase Fixed
            // se pasa por referencia para no hacer una copia del objeto
            // const para que no se pueda modificar el objeto que se asigna
        
        ~Fixed(void);                               // Destructor
        
        int getRawBits(void) const;                 // Get the raw value of the fixed point value
        void setRawBits(int const raw);             // Set the raw value of the fixed point value
        
        float toFloat(void) const;                  // Convert the fixed point value to a floating point value
        int toInt(void) const;                      // Convert the fixed point value to an integer value

    private:
    // private para que no se pueda acceder desde fuera de la clase
        int value;                                  // The raw value of the fixed point value
        static const int bits = 8;                  // The number of fractional bits
        // static para que bits sea una variable de clase y no de objeto
        // const para que bits no se pueda modificar
};

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);    // Output stream operator overload
    // sobrecarga del operador de inserción
    // sirve para cambiar la forma en la que se imprime un objeto de la clase Fixed
    // se llama cuando se usa <<
    // modifica el flujo de salida (stream) y el objeto de la clase Fixed (nbr)
    // devuelve una referencia a un objeto de la clase ostream, esto sirve para
    // poder encadenar varios operadores de inserción!!!!
    // el nombre operator<< esta predefinido, no se puede cambiar
    // el primer parámetro es un objeto de la clase ostream que quiere ser modificado
    // el segundo parámetro es un objeto de la clase Fixed que se quiere imprimir
#endif

/*
SOBRECARGA DE CONSTRUCTORES:
- permite que una clase tenga varios constructores con el mismo nombre pero con
diferentes parámetros para crear el objeto de diferentes maneras.


DESTRCUCTOR:
- es un método especial que se llama automáticamente cuando un objeto se destruye.
sin necesidad de llamarlo explícitamente.
- el momento exacto en el que se destriye un objeto depende de cómo se creó, si
se creó en el STACK, se destruirá cuando salga del SCOPE, si se creó en el HEAP,
se destruirá cuando se llame a DELETE.!!!!???

SOBRECARGA DE OPERADORES:
- permite cambiar la forma en la que se comporta un operador cuando se usa con
objetos de una clase.
- se puede sobrecargar cualquier operador, excepto los operadores de asignación
(=), selección de miembro (.), selección de miembro a través de puntero (->),
y el operador de resolución de ámbito (::).
- se tienen que llamar con al menos un operando de la clase que se está sobrecargando.
por ejemplo, para sobrecargar el operdaor << se llamraia operator<<.

*/