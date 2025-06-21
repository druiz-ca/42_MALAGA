/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:54:29 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/02/16 11:14:05 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string num_string;
    int num;

    while (1)
    {
        std::cout << "Enter the number of Zombies: " << std::endl;
        std::cin >> num_string;
        while (checknumber(num_string) == 1)
        {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin >> num_string;
        }
        break;
    }
    // convertimos el string a int (explicado abajo)
    std::istringstream iss(num_string);

    //si no se puede convertir el string a int, devuelve false
    if (!(iss >> num))
    {
        // cuando el mensaje es de error se usa std::cerr en vez de std::cout
        std::cerr << "Invalid input: not a valid integer" << std::endl;
        return (1);
    }

    // inicializamos el array de zombies con el nombre "Zombie"
    Zombie *horde = zombieHorde(num, "Zombie");

    // recorremos el array de zombies y llamamos al método announce
    for (int i = 0; i < num; i++)
    {
        std::cout << i + 1 << "º ";
        horde[i].announce();
    }

    // este delete lleva [] porque horde es un array de objetos
    delete[] horde;
    return (0);
}

/* 
SOBRECARGA DEL OPERADOR DE EXTRACION ">>" :
- sirve para extraer datos de un flujo de entrada (como std::cin).
- admite cualquier tipo de datos, como int, float, char, etc.


CONVERTIR STRING A INT:
- std::istringstream iss(num_string): creamos un objeto de tipo std::istringstream
  y le pasamos el string num_string entonces lo que hace es convertir el string
  y lo guarda en iss.
- esto funciona como std::cin, pero en vez de leer de la consola lee de un string.
- if (!(iss >> num)): si no se puede convertir el string a int, devuelve false.
*/