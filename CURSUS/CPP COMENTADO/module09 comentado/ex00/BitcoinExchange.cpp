/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:57:28 by daniel            #+#    #+#             */
/*   Updated: 2025/04/11 14:10:43 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void loadBD(map<string, double> &PriceList, string &file)
{
    // ifstream(input file stream): clase para leer datos desde un archivo
    ifstream File(file.c_str());
}

void bitcoinExchange(char *file)
{
    /* creo un contenedor de datos para almacenar los precios
    - uso el contenedor map pq es un contenedor asociativo que almacena
        pares de clave-valor, donde la clave es el nombre del producto
        y el valor es el precio
    - el contenedor map almacena los elementos en orden ascendente
    - string y double son los tipos de datos de la clave y el valor
    */
    map<string, double> PriceList;
    try
    {
        // cargo los datos del archivo en el contenedor Prices
        loadBD(PriceList, "./data.csv");
        // comparo los datos del archivo de entrada con los precios
        checkBD(PriceList, file);
    }
    catch(const exception &e)
    {
        cerr << " Error: " << e.what() << "." << endl; 
        return ;
    }
}