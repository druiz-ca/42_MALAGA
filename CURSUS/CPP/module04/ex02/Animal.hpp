/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:19:05 by daniel            #+#    #+#             */
/*   Updated: 2025/03/02 10:33:34 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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

        Animal &operator=(const Animal &copyAnimal);
        string getType() const;
        virtual void makeSound() const = 0;
        virtual Brain *getBrain() const = 0;
    
    protected:
        string _type;    
};
