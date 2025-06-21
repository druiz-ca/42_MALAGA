/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:30:05 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/02/22 13:52:24 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f); // la f al final del número indica que es un float
    Fixed const d(b);

    a = Fixed(1234.4321f); // si el const. recibe un float tengo que poner la f al final
        // la f al final del número indica que es un float (7 decimales maximo)
        // los double tienen 15 decimales de precisión
        // cout solo imprime 6 decimales maximo
        // en este caso imprime 2 decimales porque el cout redondea el número
    

    // << es un operador de inserción, se usa para imprimir en pantalla
    // >> es un operador de extracción, se usa para leer de la entrada estándar
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
        // toInt() convierte el valor de Fixed a un entero
    return (0);
}
/*

FLOAT (punto flotante)
    - se dice flotante porque la coma flota en el número es decir, puede estar en cualquier posición
    - tiene 7 decimales de precisión

FIXED (punto fijo)
    - la coma está fija en una posición (en este caso en la posición 8)
    - tiene 8 bits de precisión (8 decimales)
    - numero entero sin decimales

*/