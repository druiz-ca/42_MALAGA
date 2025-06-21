/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:16:38 by daniel            #+#    #+#             */
/*   Updated: 2025/02/11 19:18:46 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

using std::string;

// ALT + Ñ PARA ~
class ClapTrap
{
    public: // SINO PONGO PUBLIC ES PRIVADO Y NO PUEDE ACCEDER!!!
    
        ClapTrap(); // Constructor por defecto
        ClapTrap(string name); // constructor con nombre
        ClapTrap(ClapTrap &copyClapTrap);   // es obligatorio el const??
        ~ClapTrap();
        
        ClapTrap &operator =(const ClapTrap &copyClapTrap);

        /* GETS */
        unsigned int getHitPoints();
        unsigned int getEnergyPoints();
        unsigned int getDamagePoints();
        string& getName(); // pq tiene que devolver un string x referencia?? 

        /* SETS */
        void setAttackDamage(unsigned int amount);
        void setHitPoints(unsigned int amount);
        void setEnergyPoints(unsigned int amount);
        void setName(string &name); // pq hay que pasarlo por referencia???
     
        /* METODS */
        void attack(const string &name); //para que necesita pasar el nombre x ref?
        void beRepaired(unsigned int amount);
        void takeDamage(unsigned int amount);
        
        
    protected: // para acceder desde las clases derivadas    
    // si fuese private no podrian acceder  desde las clases derivadas
        string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
};

#endif