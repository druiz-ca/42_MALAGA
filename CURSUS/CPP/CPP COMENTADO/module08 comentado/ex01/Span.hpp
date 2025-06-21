/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:15:08 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/04/06 11:01:35 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>  
#include <iostream>

class Span {
public:
    // Constructor que inicializa el tamaño máximo
    Span(unsigned int n);

    // Destructor
    ~Span();

    // Añade un número al contenedor
    void addNumber(int n);

    // Encuentra el span más corto
    int shortestSpan();

    // Encuentra el span más largo
    int longestSpan();

    // Excepción para cuando no hay suficientes números
    class NotEnoughNumbersException : public exception {
    public:
        const char* what() const throw();
    };

    // Excepción para cuando se excede el tamaño máximo
    class MaxSizeException : public exception {
    public:
        const char* what() const throw();
    };

private:
    unsigned int _maxSize;         // Tamaño máximo del contenedor
    vector<int> _numbers;    // Contenedor de números
};