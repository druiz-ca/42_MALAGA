/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:56:32 by daniel            #+#    #+#             */
/*   Updated: 2025/03/01 14:28:05 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

using std::string;

class Brain
{
    public:
        Brain();
        Brain(Brain const &copy);
        ~Brain();
        Brain const &operator=(Brain const &copy);
        string const getIdea(int const &index) const;
        void setIdea(string const &idea, int const index);
    private:
        string _ideas[100];
};
