/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:17:07 by daniel            #+#    #+#             */
/*   Updated: 2025/02/11 19:25:44 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

using std::string;

            // para heredar todos los metodos y atributos de la clase ClapTrap
class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const string &name);
        ScavTrap(const ScavTrap &newScavTrap);
        ~ScavTrap();
    
        // usign se usa para traer un metodo de otra clase
        using ClapTrap::operator =;

        void attack(const std::string &name);
            // el const al final es para que este método no pueda modificar
            // las variables miembro de la clase!!
        void guardGate() const; 
};

#endif