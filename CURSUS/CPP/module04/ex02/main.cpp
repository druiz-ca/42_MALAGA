/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:54:11 by daniel            #+#    #+#             */
/*   Updated: 2025/03/02 10:32:53 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define NUM_ANIMALS 10

using std::cout;
using std::endl;

int main()
{
    Animal *canino = new Dog(); 
    Animal *gatuno = new Cat();

    canino->makeSound();
    gatuno->makeSound();

    delete canino;
    delete gatuno;
}