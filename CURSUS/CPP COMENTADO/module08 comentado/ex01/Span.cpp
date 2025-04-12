/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:14:58 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/04/06 11:22:19 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include "Span.hpp"
#include <algorithm> // Para std::sort, std::min_element, std::max_element
#include <limits>    // Para std::numeric_limits

Span::Span(unsigned int n) : _maxSize(n) {} // Constructor

Span::~Span() {} // Destructor

void Span::addNumber(int n) {
    if (_numbers.size() >= _maxSize)
        throw MaxSizeException();
    _numbers.push_back(n);
}

/* Calcula la diferencia más pequeña entre dos numeros consecutivos del contenedor */
int Span::shortestSpan() {
    if (_numbers.size() < 2)
        throw NotEnoughNumbersException();

    // creo una copia del contenedor(vector)
    vector<int> sorted = _numbers;
    // ordeno la copia
    sort(sorted.begin(), sorted.end());

    // encuentro el span más corto
    int shortest = numeric_limits<int>::max();

    // recorro el contenedor ordenado
    for (size_t i = 1; i < sorted.size(); ++i) 
    {   // calculo la diferencia entre el número actual y el anterior
        int dif = sorted[i] - sorted[i - 1];
        // si la diferencia es menor que la más corta encontrada hasta ahora
        if (dif < shortest)
            // actualizo la más corta
            shortest = dif;
    }
    return shortest;
}

int Span::longestSpan() {
    if (_numbers.size() < 2)
        throw NotEnoughNumbersException();

    // encuentro el valor más pequeño del contenedor
    int min = *min_element(_numbers.begin(), _numbers.end());
    // encuentro el valor más grande del contenedor
    int max = *max_element(_numbers.begin(), _numbers.end());
    // devuelvo la diferencia entre el valor más grande y el más pequeño
    return max - min;
}

const char* Span::NotEnoughNumbersException::what() const throw() {
    return "not enough numbers in the container";
}

const char* Span::MaxSizeException::what() const throw() {
    return "not enough space in the container";
}