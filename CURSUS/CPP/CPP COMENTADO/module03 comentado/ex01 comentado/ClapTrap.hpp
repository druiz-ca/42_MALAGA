/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:22:07 by daniel            #+#    #+#             */
/*   Updated: 2025/02/09 12:29:57 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    public:
        // los constructores y destructores no llevan tipo de retorno
        // todos los const. se llaman igual, en funcion del parametro que reciban
            // se ejecuta uno u otro
        //si cambio en algo el nombre ClapTrap dará error!! detecta que tiene que ser igual
        ClapTrap();                     // constructor por defecto
        ClapTrap(std::string name);    // constructor con parámetro
        ClapTrap(const ClapTrap &copyClapTrap); // constructor de copia
            // para crear un objeto a partir de otro objeto de la misma clase
        ~ClapTrap();                    // destructor

        ClapTrap &operator=(const ClapTrap &copyClapTrap); // sobrecarga del operador de asignación
            // para asignar los valores de un objeto a otro objeto de la misma clase
        
        void attack(const std::string &target); // método de ataque
            // envia como parametro el nombre del objetivo al que se va a atacar
        void beRepaired(unsigned int amount); // método de reparación
            // envia como parametro la cantidad de puntos de vida que se van a recuperar
        void takeDamage(unsigned int amount); // método para aplicar daño(resta vida)?
            // envia como parametro la cantidad de puntos de vida que se van a perder
        void setAttackDamage(unsigned int num); // método para establecer el daño de ? ataque
            // envia como parametro la cantidad de daño que se va a hacer
        void setEnergyPoints(unsigned int num); // método para establecer los puntos de energía
            // envia como parametro la cantidad de puntos de energía que se va a asignar
        void setHitPoints(unsigned int num); // método para establecer los puntos de vida
            // envia como parametro la cantidad de puntos de vida que se va a asignar
        void setName(const std::string &name); // método para establecer el nombre
            // envia como parametro el nombre que se va a asignar
            // lo hace por referencia para no hacer una copia del string y evitar gastar memoria copiando


        // los siguientes métodos llevan const porque no va a 
        //modificar los valores de los objetos, los anteriore si
        //porque si los modificaban 
        
        const std::string& getName() const; // método para obtener el nombre
            // devuelve el nombre del objeto
            // el const al final de la función indica que no se va a modificar los valores del objeto
                // no va dentro del parentesis porque no es un parametro sino una condición del metodo
        unsigned int getHitPoints() const; // método para obtener los puntos de vida
        unsigned int getEnergyPoints() const; // método para obtener los puntos de energía
        unsigned int getAttackDamage() const; // método para obtener el daño de ataque

    protected: // los miembros protegidos pueden ser accedidos por las clases derivadas, es decir, las clases que heredan de esta clase pero no por otros usuarios de la clase. sirve para almacenar datos que no deben ser cambiados desde fuera de la clase

        std::string _name; // nombre del ClapTrap
        
        unsigned int _attackDamage; // daño de ataque
        unsigned int _energyPoints; // puntos de energía
        unsigned int _hitPoints; // puntos de vida
            // se le pone_ delante para indicar que es una variable privada y diferenciarla de las variables locales es decir, las que se declaran dentro de un método
};


/* los miembros de una clase pueden ser: 
- public
- private = solo se puede acceder desde la misma clase
- protected = es como private pero se puede acceder desde las clases derivadas 
*/
#endif