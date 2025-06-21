/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:40:32 by daniel            #+#    #+#             */
/*   Updated: 2025/04/05 11:07:05 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector> // para std::vector
#include <algorithm> // para std::find

using namespace std;


// T &container es una referencia a un contenedor genérico (de la STL)
// Standard Template Library (vector, list, map, etc.)
template<typename T>
bool easyfind(T &container, int i)
{
    // busca el elemento i en el contenedor desde el principio hasta el final
    return (find(container.begin(), container.end(), i) != container.end());
    // si lo encuentra devuelve true, si no lo encuentra devuelve false
    // find() devuelve un iterador al primer elemento que coincide con el valor buscado
    // si no lo encuentra devuelve container.end()
}