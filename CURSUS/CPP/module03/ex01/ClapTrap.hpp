/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:22:07 by daniel            #+#    #+#             */
/*   Updated: 2025/02/15 14:18:11 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    public:

        ClapTrap();                     
        ClapTrap(std::string name);   
        ClapTrap(const ClapTrap &copyClapTrap); 
        ~ClapTrap();             

        ClapTrap &operator=(const ClapTrap &copyClapTrap);         
        void attack(const std::string &target); 
        void beRepaired(unsigned int amount); 
        void takeDamage(unsigned int amount); 
        void setAttackDamage(unsigned int num); 
        void setEnergyPoints(unsigned int num); 
        void setHitPoints(unsigned int num); 
        void setName(const std::string &name);
        const std::string& getName() const; 
        unsigned int getHitPoints() const; 
        unsigned int getEnergyPoints() const;
        unsigned int getAttackDamage() const; 

    protected: 

        std::string _name; 
        
        unsigned int _attackDamage; 
        unsigned int _energyPoints; 
        unsigned int _hitPoints; 
};
#endif