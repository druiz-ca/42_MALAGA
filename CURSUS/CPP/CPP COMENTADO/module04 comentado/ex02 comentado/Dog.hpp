/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:18:36 by daniel            #+#    #+#             */
/*   Updated: 2025/03/01 12:39:57 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog : virtual public Animal
{
    public:
        Dog();
        Dog(const Dog &copy);
        virtual ~Dog();

        Dog &operator=(Dog const &src);
        void buildDogIdeas (std::string const &idea, int const i);
        void getDogIdeas (int const index);
        void makeSound() const;
        Brain *getBrain() const;

    private:
        Brain *_brain;
};