/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:54:11 by daniel            #+#    #+#             */
/*   Updated: 2025/03/02 11:43:33 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define NUM_ANIMALS 10
using std::cout;
using std::endl;

int main()
{
    {
        const Animal *lotsOfAnimals[NUM_ANIMALS];
        for (int i = 0; i < 10; i++)
        {
            if (i < NUM_ANIMALS / 2)
                lotsOfAnimals[i] = new Dog();
            else
                lotsOfAnimals[i] = new Cat();
        }

        Brain *DogBrain = lotsOfAnimals[0]->getBrain();
        Brain *CatBrain = lotsOfAnimals[5]->getBrain();
        cout << lotsOfAnimals[0]->getType() << endl;
        cout << lotsOfAnimals[5]->getType() << endl;
        cout << "The Dog's thought is: "  << DogBrain->getIdea(0) << endl;
        cout << "The Cat's thought is: " << CatBrain->getIdea(0) << endl;
        DogBrain->setIdea("I have a Dog thought", 0);
        CatBrain->setIdea("I have a Cat thought", 0);
        cout << "The Dog's thought is: " << DogBrain->getIdea(0) << endl;
        cout << "The Cat's thought is: " << CatBrain->getIdea(0) << endl;

        for (int i = 0; i < NUM_ANIMALS; i++)
            delete lotsOfAnimals[i];
    }
    cout << "----------------------------------------------" << endl;
    {
        cout << "deep copy Dog copy constructor: " << endl;
        cout << "----------------------------------------------" << endl;

		Dog *dogA = new Dog;
		Dog *dogB = new Dog(*dogA);

		delete dogA;
		delete dogB;
    }
    cout << "----------------------------------------------" << endl;
	{
		cout << "deep copy Dog assignment operator : " << std::endl;
        cout << "----------------------------------------------" << endl;

		Dog *dogA = new Dog;
		Dog *dogB = new Dog;

		*dogA = *dogB;
		delete dogA;
		delete dogB;
	}
    cout << "----------------------------------------------" << endl;
	{
		cout << "deep copy Cat copy constructor:" << endl;
        cout << "----------------------------------------------" << endl;

		Cat *catA = new Cat;
		Cat *catB = new Cat(*catA);

		delete catA;
		delete catB;
	}
    cout << "----------------------------------------------" << endl;
	{
		std::cout << "deep copy Cat assignment operator : " << std::endl;
        cout << "----------------------------------------------" << endl;

		Cat *catA = new Cat;
		Cat *catB = new Cat;

		*catA = *catB;
		delete catA;
		delete catB;
	}
    return 0;
}