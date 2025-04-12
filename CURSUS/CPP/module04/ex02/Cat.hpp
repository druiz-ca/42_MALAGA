/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:18:59 by daniel            #+#    #+#             */
/*   Updated: 2025/03/02 10:34:03 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat : virtual public Animal
{
    public:
        Cat();
        Cat(const Cat &copyCat);
        virtual ~Cat();

        Cat &operator=(Cat const &src);
        void buildCatIdeas (std::string const &idea, int const i);
        void getCatIdeas (int const index);
        void makeSound() const; 
        Brain *getBrain() const;

    private:
        Brain *_brain;
};