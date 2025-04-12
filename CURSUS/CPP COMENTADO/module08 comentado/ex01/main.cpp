/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:14:46 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/04/06 13:00:50 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib> // Para rand()
/*
calcula la distancia(SPAN) mas corta entre dos numeros y la mas larga

- CONTAINER :
    - es lo mismo que un array, pero con la diferencia de que el contenedor
    puede cambiar de tamaño durante su ejecución, mientras que el array no. 
    - util para cuando necesita almacenar datos de los que no se sabe previamente su tamaño.
    - puede ser vector, list, deque, stack, queue, priority_queue, etc.
    - El contenedor tiene funciones para añadir, eliminar y acceder a los elementos del array.
        - push_back() para añadir elementos al final del contenedor,
        - pop_back() para eliminar el último elemento del contenedor,
        - size() para obtener el número de elementos en el contenedor,
        - clear() para eliminar todos los elementos del contenedor,
        - empty() para comprobar si el contenedor está vacío.
        - begin() para obtener un iterador al primer elemento del contenedor,
        - end() para obtener un iterador al último elemento del contenedor,
*/
int main() {
    try {
        Span sp(5); // Tamaño máximo de 5
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

/* 
int main() {
    try {
        Span sp(10000);
        for (int i = 0; i < 10000; ++i) {
            sp.addNumber(rand());
        }

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
} */
