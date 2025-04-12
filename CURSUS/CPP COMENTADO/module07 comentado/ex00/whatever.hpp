/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:27:15 by daniel            #+#    #+#             */
/*   Updated: 2025/04/03 14:25:35 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
/* Define una plantailla de función (template <typename T)
- T es un parámetro de tipo genérico, es decir, que swap puede trabajar
 con cualquier tipo de dato
- T es un tipo de dato que se determina en tiempo de compilación
- template <template_name> va antes de la declaración de la función para
indicar que es una plantilla y que el tipo de dato genérico que usará es T 
- en función de los parámetros que le pasemos a la función, el compilador generará
una versión de la función para cada tipo de dato:
    - para int-> swap(int &first, int &second)
    - para char-> swap(char &first, char &second)
 */
template <typename T>
void swap(T &first, T &second)
{
    T third;
    third = first;
    first = second;
    second = third;
}

template <typename T>
T min(T &first, T &second)
{
    if (first < second)
        return (first);
    return (second);
}

template <typename T>
T max(T &first, T &second)
{
    if (first > second)
        return (first);
    return (second);
}