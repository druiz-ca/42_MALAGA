/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:59:42 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/01/21 17:54:15 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

class Zombie
{
    public:
        // un método (función) se puede desarrollar dentro de la clase
        // pero no necesita el nombre de la clase delante (Zombie::)
        // si se desarrolla dentro entonces hay que acabar con ;
        // los const. y destructores se tienen que llamar igual que la clase
        
        // constructor con parámetro
        Zombie(std::string name);
        // constructor por defecto (abajo se explica)
        Zombie(void);
        ~Zombie(void);
        void announce(void);
        void putname(std::string name);

    private:
        std::string name;
        /* las var declaradas en private solo son accesibles desde los 
        métodos de la misma clase */
};

Zombie *zombieHorde(int N, std::string name);
int checknumber(std::string str);

#endif

/*
    SOBRECARGA DE CONSTRUCTORES:
    - es tener varios constructores con el mismo nombre pero con diferentes
    parámetros.
    - Constructor por defecto: es un constructor que no tiene parámetros.
    sirve para inicializar las variables miembro de la clase con valores
    predeterminados o sin valores para luego asignarles valores + adelante.
    - Constructor con parámetros: es un constructor que tiene uno o más
    parámetros. Sirve para inicializar las variables miembro de la clase con
    valores específicos aportados por el usuario.
    
    La razón para tener ambos constructores es proporcionar flexibilidad
    en la creación de objetos Zombie. Dependiendo de la situación, 
    podrías necesitar crear un Zombie con un nombre específico o 
    simplemente crear un Zombie sin nombre y asignárselo más tarde.
    Tener ambos constructores te permite manejar ambas situaciones de
    manera eficiente.
*/