/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:18:59 by daniel            #+#    #+#             */
/*   Updated: 2025/02/28 16:46:25 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// poner virtual aqui evita que se llame al constructor de la clase base
// en la clase derivada y evita el problema del diamante
// es decir que virtual hace que no se puede llamar al constructor de la clase base
class Cat : virtual public Animal
{
    public:
        Cat();
        Cat(const Cat &copyCat);
        virtual ~Cat(); // 

        using Animal::operator=; //using porque no se va a redefinir sino que
        // estoy usando el operador de la clase base
        void makeSound() const; // esta no la traigo(using) pq hará otra cosa
};