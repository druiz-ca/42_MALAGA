/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:08:04 by daniel            #+#    #+#             */
/*   Updated: 2025/04/03 12:48:26 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
// uintptr_t --> unsigned int pointer type

/* convierte el puntero que apunta a la estrucura data1 a su valor entero
extrayendo la dirección de memoria a la que apunta y devolciendola en un uintptr */
uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}


//el uintptr_t es un tipo de dato que es un entero sin signo que es capaz de 
//almacenar la dirección de memoria de un puntero

/* vuelve a convertir la dirección de memoria en un puntero */
Data *Serializer::deserialize(uintptr_t raw)
{// reinterpret_cast se usa para convertir el raw a un valor de tipo Data*
    return (reinterpret_cast<Data *>(raw));
}