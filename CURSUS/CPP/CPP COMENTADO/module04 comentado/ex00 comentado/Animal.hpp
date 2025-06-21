/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:19:05 by daniel            #+#    #+#             */
/*   Updated: 2025/02/28 14:51:15 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

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
        // si eliminase el virtual, el destr. de la clase base se ejecutaria
        // antes del de la clase derivada habría fuga de datos de la clase derivada

        Animal &operator=(const Animal &copyAnimal);
        string getType() const;
        void setType(const string &type);
        // virtual para q se pueda sobreescribir en las clases derivadas
        // esta ft se puede redefinir en las clases derivadas si se 
        // llama con un puntero o una referencia a la clase base
        // si en la clase derivada no se redefine, se usara tal cual
        virtual void makeSound() const;    
    
    protected:
        string _type;    
        Animal(const string &type);// en protected pq se llama desde otra clase
};

#endif