/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:16:38 by daniel            #+#    #+#             */
/*   Updated: 2025/02/11 21:28:36 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

using std::string;

// ALT + Ñ PARA ~
class ClapTrap
{
    public: 
    
        ClapTrap(); 
        ClapTrap(string name); 
        ClapTrap(ClapTrap &copyClapTrap);   
        ~ClapTrap();
        
        ClapTrap &operator =(const ClapTrap &copyClapTrap);

        /* GETS */
        unsigned int getHitPoints();
        unsigned int getEnergyPoints();
        unsigned int getDamagePoints();
        string& getName(); 

        /* SETS */
        void setAttackDamage(unsigned int amount);
        void setHitPoints(unsigned int amount);
        void setEnergyPoints(unsigned int amount);
        void setName(string &name); 
     
        /* METODS */
        void attack(const string &name); 
        void beRepaired(unsigned int amount);
        void takeDamage(unsigned int amount);
        
        
    protected: 
        string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
};

#endif