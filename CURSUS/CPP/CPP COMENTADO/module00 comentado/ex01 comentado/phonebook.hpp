/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:13:53 by daniel            #+#    #+#             */
/*   Updated: 2025/02/15 11:07:09 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream> // para usar std::cout y std::cin
#include <string.h> // para usar std::string
#include <iomanip> // para usar std::setw
#include <limits> // para usar std::numeric_limits
#include <cstdlib> // para usar la función system
#include <cstring> // para usar la función strcpy


class Contact
{
    public:
        // si no se especifica el modificador de acceso, por defecto es private
        std::string     name;
        std::string     lastname;
        std::string     nickName;
        std::string     phone;
        std::string     secret;
};

class Phonebook
{
    public:
        Contact Array_contacts[9];
        int     num;
};

#endif
