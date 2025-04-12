/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:50:49 by daniel            #+#    #+#             */
/*   Updated: 2025/04/04 14:11:52 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    // el <int> indica que es una clase plantilla y que el tipo de dato que se va 
    // a almacenar en el array es int
    Array<int> arr(5);
    // inicializo el array con valores del 1 al 5
    for (int i = 0; i < 5; i++)
        arr[i] = i + 1;
    
    // muestro los valores del array
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;

    // intento acceder a un índice fuera de rango
    try
    {
        cout << arr[5] << endl; // This will throw an exception
    }
    catch (const std::out_of_range &e)
    {
        cout << e.what() << endl;
    }

    return 0;
    
}