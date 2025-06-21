/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:18:36 by daniel            #+#    #+#             */
/*   Updated: 2025/02/13 19:40:54 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &);
        virtual ~Dog();

        // cuando se trae un metodo de otra clase no necesita poner los parametros
        using Animal::operator=;
        void makeSound() const;
};