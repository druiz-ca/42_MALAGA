/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:58:08 by daniel            #+#    #+#             */
/*   Updated: 2025/02/04 19:54:10 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    public:
        ClapTrap();                            // Default constructor
        ClapTrap(std::string name);           // Parameterized constructor
        ClapTrap(const ClapTrap &newCT);          // Copy constructor
        ~ClapTrap();                            // Destructor
        
        // para cuando quiero copiar un objeto en otro
        // por eso recibe un objeto y devuelve un objeto
        // ambos por referencia para no hacer copias
        // lo manda como constante para que no se pueda modificar
        ClapTrap &operator=(const ClapTrap &newCT); // Assignment operator
        

        // devuelve un string por referencia constante(no se puede modificar)
        // los parametros son constantes para que no se puedan modificar
        // el const va fuera del parentesis de la función!!!
        const std::string &getName() const;        // Get the name of the ClapTrap

        void attack(const std::string &target);    // Attack method
        void beRepaired(unsigned int amount);      // Be repaired method
        void takeDamage(unsigned int amount);      // Take damage method
        void setAttackDamage(unsigned int attackDamage); // Set the attack damage of the ClapTrap
        void setEnergyPoints(unsigned int energyPoints); // Set the energy points of the ClapTrap
        void setHitPoints(unsigned int hitPoints); // Set the hit points of the ClapTrap
        void setName(const std::string &name);     // Set the name of the ClapTrap

        unsigned int getHitPoints() const;         // Get the hit points of the ClapTrap
        unsigned int getEnergyPoints() const;      // Get the energy points of the ClapTrap
        unsigned int getAttackDamage() const;      // Get the attack damage of the ClapTrap

    private:
        std::string _name;                        // Name of the ClapTrap
        unsigned int _attackDamage;               // Attack damage of the ClapTrap
        unsigned int _energyPoints;               // Energy points of the ClapTrap
        unsigned int _hitPoints;                  // Hit points of the ClapTrap
        // se pone _ delante de las variables miembro para diferenciarlas
        // de las variables locales

        // se declaran en private para que no se puedan modificar desde fuera
        // de la clase
};


#endif