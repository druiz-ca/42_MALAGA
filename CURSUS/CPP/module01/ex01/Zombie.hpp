/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:59:42 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/01/21 18:02:20 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

class Zombie
{
    public:
    
        Zombie(std::string name);
        Zombie(void);
        ~Zombie(void);
        void announce(void);
        void putname(std::string name);

    private:
        std::string name;
};

Zombie *zombieHorde(int N, std::string name);
int checknumber(std::string str);

#endif
