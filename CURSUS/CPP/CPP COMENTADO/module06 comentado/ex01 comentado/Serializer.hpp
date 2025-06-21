/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:08:32 by daniel            #+#    #+#             */
/*   Updated: 2025/04/02 17:53:57 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

/* la estructura de un objeto y de una estructura es identica en todo: 
- la única diferencia es que en una estructura los miembros son por defecto públicos
- en una clase los miembros son por defecto privados
por lo demás todo es igual: se pueden tener métodos, constructores, destructores, etc. */
struct Data
{
    int something;
};

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
        
    private:
        Serializer();
        ~Serializer();
};

