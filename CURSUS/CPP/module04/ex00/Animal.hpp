/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:19:05 by daniel            #+#    #+#             */
/*   Updated: 2025/02/13 21:02:46 by daniel           ###   ########.fr       */
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

        Animal &operator=(const Animal &copyAnimal);
        string getType() const;
        void setType(const string &type);
        virtual void makeSound() const;        
    
    protected:
        string _type;    
        Animal(const string &type);
};

#endif