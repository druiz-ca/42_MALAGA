/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:22:20 by daniel            #+#    #+#             */
/*   Updated: 2025/01/27 20:04:55 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
# define HARL_CPP

#include <string>
#include <iostream>

class Harl
{
    public:
        void complain(std::string type);
    
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
};

#endif
