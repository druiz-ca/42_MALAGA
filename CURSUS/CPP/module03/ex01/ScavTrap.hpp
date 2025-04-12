/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:22:26 by daniel            #+#    #+#             */
/*   Updated: 2025/02/15 14:19:23 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
        
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &copyScapTrap);
        ~ScavTrap();
        
        using ClapTrap::operator =;
        void attack(const std::string &target);

        void guardGate() const;       
};

#endif