/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:13:17 by daniel            #+#    #+#             */
/*   Updated: 2025/01/21 18:13:18 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
    public:
    
    void announce(void);
    Zombie(std::string name);
    ~Zombie(void);

    private:

    std::string name;
};


Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif