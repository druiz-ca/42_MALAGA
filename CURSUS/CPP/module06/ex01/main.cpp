/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:07:34 by daniel            #+#    #+#             */
/*   Updated: 2025/04/03 13:00:20 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
using namespace std;

int main()
{
    Data data1;
    Data data2;
    
    data1.something = 42;
    data2.something = 21;

    Data *data = &data1;

    cout << "Data has changed his pointer to Data 1 and his address is: " << data << endl;
    cout << "Variable something of Data is: " << data->something << endl << endl;

    uintptr_t serialized = Serializer::serialize(data);
    cout << "Data Serialized: " << serialized << endl << endl;

    data = &data2;
    cout << "Data has changed his pointer to Data 2 and his address is: " << data << endl;
    cout << "Variable something of Data is: " << data->something << endl << endl;

    data = Serializer::deserialize(serialized);
    cout << "Data Des-Serialized: " << serialized << endl;
    cout << "Data has changed his pointer to the value Des-Serialized" << endl << endl;

    cout << "Data has his pointer now in the address: " << data << endl;
    cout << "Variable something of Data is: " << data->something << endl << endl;
    
}