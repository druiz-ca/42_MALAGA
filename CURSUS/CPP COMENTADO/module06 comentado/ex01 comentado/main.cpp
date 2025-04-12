/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:07:34 by daniel            #+#    #+#             */
/*   Updated: 2025/04/03 12:46:38 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
using namespace std;

/* serializar: proceso de transformar un objeto o dato en un formato que 
puede ser almacenado o transmitido y posteriormente reconstruido.*/
int main()
{
    Data data1; //creo una estructura de tipo Data
    Data data2;
    
    data1.something = 42; //le asigno un valor a la variable de la estructura
    data2.something = 21;

    // creo un puntero de tipo Data y lo inicializo con la dirección de data1
    Data *data = &data1;

    // muestro la dirección de data1 y el valor de something
    cout << "Data has changed his pointer to Data 1 and his address is: " << data << endl;
    cout << "Variable something of Data is: " << data->something << endl << endl;

    // creo una variable de tipo uintptr_t(entero sin signo(para poder almacenar la dir de un puntero))
        // y la inicializo con la dirección de data
    // serializo data (guardo la dirección de data en serialized)
    uintptr_t serialized = Serializer::serialize(data);
    cout << "Data Serialized: " << serialized << endl << endl;

    // cambio el puntero dara para que apunte ahora a data2
    data = &data2;
    cout << "Data has changed his pointer to Data 2 and his address is: " << data << endl;
    cout << "Variable something of Data is: " << data->something << endl << endl;

    // des-serializo data (guardo la dirección que hay en serialized en data )
    data = Serializer::deserialize(serialized);
    cout << "Data Des-Serialized: " << serialized << endl;
    cout << "Data has changed his pointer to the value Des-Serialized" << endl << endl;

    // muestro la dirección de data y el valor de something
    cout << "Data has his pointer now in the address: " << data << endl;
    cout << "Variable something of Data is: " << data->something << endl << endl;
    
}