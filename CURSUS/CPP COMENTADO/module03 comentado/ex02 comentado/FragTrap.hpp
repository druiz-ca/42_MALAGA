/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:17:50 by daniel            #+#    #+#             */
/*   Updated: 2025/02/11 21:23:49 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::string;
using std::endl;

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const string &name);
        FragTrap(const FragTrap &newFragTRap);
        ~FragTrap();
    
    using ClapTrap::operator =;
    void highFiveGuys(void) const; // pq necesita poner void sino manda nada???
    
};