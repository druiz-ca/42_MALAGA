/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:56:25 by daniel            #+#    #+#             */
/*   Updated: 2025/03/01 14:28:00 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constructor default is called" << std::endl;
}

Brain::Brain(Brain const &copy)
{
    std::cout << "Brain Copy constructor is called" << std::endl;
    *this = copy;
}

Brain::~Brain()
{
    std::cout << "Brain destructor is called" << std::endl;
}

Brain const &Brain::operator=(Brain const &copy)
{
    std::copy(copy._ideas, copy._ideas + 100, this->_ideas);
    std::cout << "Assignment operator for Brain called" << std::endl;
    return (*this);
}

std::string const Brain::getIdea(int const &index) const
{
    if (index >= 0 && index < 100)
        return (this->_ideas[index]);
    return (this->_ideas[0]); 
}

void Brain::setIdea(std::string const &idea, int const index)
{
    if (index >= 0 && index < 100)
        this->_ideas[index] = idea;
}