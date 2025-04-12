/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:54:11 by daniel            #+#    #+#             */
/*   Updated: 2025/03/01 14:16:48 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define NUM_ANIMALS 10

using std::cout;
using std::endl;

int main()
{
    // es polimorfismo pq se crea un objeto de una clase y se asigna 
    // a un puntero de la clase base
    // se puede asignar un objeto de una clase derivada a un puntero de la clase base
    // porque la clase derivada tiene todos los atributos y métodos de la clase base
    // porque Dog se ha creado a partir de Animal
    Animal *canino = new Dog(); // no se puede llamar igual el objeto que la clase
    Animal *gatuno = new Cat();

    canino->makeSound();
    gatuno->makeSound();

    delete canino;
    delete gatuno;
}
/* 
- la clase animal no debe ser instanciable:
    es decir que nadie pueda crear una instancia(objeto) de ella
    se logra teniendo al menos una función miembro de tipo 
    vistual pura (es decir que sea = 0)
*/