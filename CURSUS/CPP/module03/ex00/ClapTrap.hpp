/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:58:08 by daniel            #+#    #+#             */
/*   Updated: 2025/02/15 14:15:32 by druiz-ca         ###   ########.fr       */
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
        ClapTrap(const ClapTrap &newCT);         
        ~ClapTrap();                            
        
        ClapTrap &operator=(const ClapTrap &newCT); 
        
        const std::string &getName() const;       

        void attack(const std::string &target);   
        void beRepaired(unsigned int amount);     
        void takeDamage(unsigned int amount);     
        void setAttackDamage(unsigned int attackDamage); 
        void setEnergyPoints(unsigned int energyPoints); 
        void setHitPoints(unsigned int hitPoints);
        void setName(const std::string &name);     

        unsigned int getHitPoints() const;        
        unsigned int getEnergyPoints() const;      
        unsigned int getAttackDamage() const;      

    private:
        std::string _name;                       
        unsigned int _attackDamage;             
        unsigned int _energyPoints;               
        unsigned int _hitPoints;                 
};


#endif