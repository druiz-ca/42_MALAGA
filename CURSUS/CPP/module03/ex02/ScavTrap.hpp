/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:17:07 by daniel            #+#    #+#             */
/*   Updated: 2025/02/11 21:29:16 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

using std::string;

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const string &name);
        ScavTrap(const ScavTrap &newScavTrap);
        ~ScavTrap();
    
        using ClapTrap::operator =;

        void attack(const std::string &name);
        void guardGate() const; 
};

#endif