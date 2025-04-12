/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:44:54 by daniel            #+#    #+#             */
/*   Updated: 2025/01/29 20:03:07 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    // cuando se pone entre () a la hora de declarar un objeto se llama al constructor
    // lo que hace es una copia del objeto que se le pasa por parámetro
    // resumen: se creara un objeto b con el valor de a
    Fixed b(a);
    Fixed c;

    c = b;
    // la diferencia entre

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    
    return (0);
}
/*
Basicamente, el ejercicio es para ver la diferencia entre
hacer una copia de un objeto usando un  CONSTRUCTOR DE DE COPIA
y entre usar el operador de asignacion = */