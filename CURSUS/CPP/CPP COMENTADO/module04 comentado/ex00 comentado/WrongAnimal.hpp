/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:17:54 by daniel            #+#    #+#             */
/*   Updated: 2025/02/13 20:23:33 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::string;
using std::endl;

class WrongAnimal 
{
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        virtual ~WrongAnimal();

        WrongAnimal& operator=(const WrongAnimal &copy);
        const string& getType() const;
        void setType(const string &type);
        void makeSound() const;

    protected:
        string _type;
        WrongAnimal(const string &type);
};