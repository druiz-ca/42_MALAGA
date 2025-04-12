/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:37:15 by daniel            #+#    #+#             */
/*   Updated: 2025/04/05 10:59:12 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/* PLANTILLAS DE CONTAINER 
    - estrcutra de datos dinámica
    - la diferencia con los arrays es que pueden cambiar de tamaño durante la ejecución
        - ideal para almanecar datos de los que no se conoce previamente su tamaño
    
*/
int main()
{
    vector<int> container;
    // inserta el 1 en el final del contenedor
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);

    // busca el 2 en el contenedor
    if (easyfind(container, 2))
        cout << "Container contains that Int" << endl;
    else
        cout << "Container not contains that Int" << endl;

    // busca el 4 en el contenedor
    if (easyfind(container, 4))
        cout << "Container contains that Int" << endl;
    else
        cout << "Container not contains that Int" << endl;

    
}