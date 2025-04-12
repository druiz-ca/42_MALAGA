/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:17:14 by daniel            #+#    #+#             */
/*   Updated: 2025/02/13 20:45:51 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    cout << "WrongCat default constructor is called" << endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal("WrongCat")
{
    *this = copy;
    cout << "WrongCat copy constructor is called" << endl;
}

WrongCat::~WrongCat()
{
    cout << "WrongCat destructor is called" << endl;      
}

void WrongCat::makeSound() const
{
    cout << "WrongCat sound" << endl;
}