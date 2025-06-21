/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:19:05 by daniel            #+#    #+#             */
/*   Updated: 2025/03/01 14:13:23 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
// el pragma once es para que no se incluya dos veces el mismo archivo
// en el caso de que se incluya dos veces el mismo archivo, el compilador 
// dará error de redefinición de clases, funciones, variables, etc.

#include <iostream>

#include "Brain.hpp"

using std::cout;
using std::endl;
using std::string;


/* Cuando una clase es abstracta solo se puede usar para crear otra clase 
porque al tener una función virtual pura, esa función se tendrá que definir
en la clase derivada porque en la clase base no está definida (desarrollada)
entonces daría error porque se estaría creando un objeto con una función 
declarada en la librería que no está definida en la clase base (en el .cpp) */
class Animal
{   // Clase abstracta: almenos tiene una función pura virtual ( = 0)
    // y con eso ya no se puede instanciar un objeto de esta clase
    public:
        Animal();
        Animal(const Animal &copyAnimal);
        virtual ~Animal(); 
        // virtual para asegurar que el destr. de la clase derivada
        // se ejecute antes del de la clase base

        Animal &operator=(const Animal &copyAnimal);
        string getType() const;
        // estas dos funciones son virtual pq se van a sobreescribir 
        // en las clases derivadas
        virtual void makeSound() const = 0;
        // virtual indica que puede ser redefinida en las clases derivadas
        // el = 0 indica que es una funcion pura virtual y que cualquier clase
        // que la herede debe implementarla porque no esta definida en la clase base   
        virtual Brain *getBrain() const = 0;
    
    protected:
        string _type;    
};
