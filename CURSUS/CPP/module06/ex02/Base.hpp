/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:58:08 by daniel            #+#    #+#             */
/*   Updated: 2025/04/03 13:01:02 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <unistd.h> 

using namespace std;

class Base
{
    public:
        virtual ~Base() {};
};

class A: public Base{};
class B: public Base{};
class C: public Base{};
