/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:58:08 by daniel            #+#    #+#             */
/*   Updated: 2025/04/02 13:07:22 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <unistd.h> // para el sleep

using namespace std;

class Base
{
    public:
        virtual ~Base() {}; // sin los corchetes da error
        // virtual para que se pueda sobreescribir en las clases derivadas
};

class A: public Base{};
class B: public Base{};
class C: public Base{};
