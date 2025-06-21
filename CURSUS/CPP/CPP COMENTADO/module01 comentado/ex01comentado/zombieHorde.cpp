/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:59:44 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/01/21 18:00:27 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    // como no se va a pasar por parametro el nombre del zombie por defecto 
    // usará el constructor por defecto
    Zombie *horde = new Zombie[N];
    
    for (int i = 0; i < N; i++)
        horde[i].putname(name); // explico abajo
    return (horde);
}

/*
FORMAS DE INICIALIZAR/CREAR UN OBJETO:
- Crear un objeto en la pila (stack): 
    - Se crea el objeto y se llama al constructor.
    - Se destruye el objeto y se llama al destructor.

- Crear un objeto en el heap (heap):
    - Se llama a new para crear el objeto y se llama al constructor.
    - Se llama a delete para destruir el objeto y se llama al destructor.

LLAMAR A UN MÉTODO QUE ESTA DENTRO DE UNA CLASE:
- Para llamar a un método que está dentro de una clase se usa el operador
"." (punto).
- si fuera un puntero a un objeto se usa el operador "->"
- solo se puede acceder a un método de una clase desde un objeto de esa clase.
(como Horde es un puntero a un objeto de la clase Zombie)

*/