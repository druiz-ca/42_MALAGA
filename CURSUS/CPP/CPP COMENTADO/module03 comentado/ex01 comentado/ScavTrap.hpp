/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:22:26 by daniel            #+#    #+#             */
/*   Updated: 2025/02/09 18:29:42 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp" // para heredar de ClapTrap hay que incluir su archivo

// scavTrap es una clase derivada de ClapTrap,que hereda de 
// los atributos y métodos de ClapTrap
// : public ClapTrap indica que ScavTrap hereda de ClapTrap
// se pone public para que los atributos y métodos de ClapTrap
// sean accesibles desde ScavTrap
class ScavTrap: public ClapTrap
{
    public:// sino pongo public no puedo acceder a los metodos de la clase base
    // es decir que por defecto es privado!!!
        
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &copyScapTrap);
        ~ScavTrap();
        
        using ClapTrap::operator =;// using para usar el operador = de ClapTrap

        // si se declara otro metodo que se llama igual que uno de la clase base
        // se sobreescribe, esto es cuando va a tener diferente comportamiento
        void attack(const std::string &target);

        // guardGAte sirve para que ScavTrap entre en modo guardia
        void guardGate() const; // el const fuera de los parentesis indica 
        // que no se va a modificar el objeto que llama a la función
      
};

#endif