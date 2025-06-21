/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:19:05 by daniel            #+#    #+#             */
/*   Updated: 2025/03/02 11:59:33 by druiz-ca         ###   ########.fr       */
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

class Animal
{
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
        // el = 0 indica que es una funcion pura virtual y que la clase es abstracta    
        virtual Brain *getBrain() const = 0;
    
    protected:
        string _type;    
};
