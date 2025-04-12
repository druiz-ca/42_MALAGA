/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:54:11 by daniel            #+#    #+#             */
/*   Updated: 2025/03/01 14:18:54 by druiz-ca         ###   ########.fr       */
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
        // no se puede hacer pq getBrain es virtual
        Brain *CatBrain = lotsOfAnimals[5]->getBrain();
        cout << lotsOfAnimals[0]->getType() << endl;
        cout << lotsOfAnimals[5]->getType() << endl;
        cout << "The Dog's thought is \"" << DogBrain->getIdea(0) << "\"" << endl;
        cout << "The Cat's thought is \"" << CatBrain->getIdea(0) << "\"" << endl;
        DogBrain->setIdea("I have a Dog thought", 0);
        CatBrain->setIdea("I have a Cat thought", 0);
        cout << "The Dog's thought is \"" << DogBrain->getIdea(0) << "\"" << endl;
        cout << "The Cat's thought is \"" << CatBrain->getIdea(0) << "\"" << endl;

        for (int i = 0; i < NUM_ANIMALS; i++)
            delete lotsOfAnimals[i];
    }
    std::cout << "-------------------------------------\n";
    {
        cout << "Checker deep copy of Dog class using copy constructor:\n" << endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog(*dogA);

		delete dogA;
		delete dogB;
    }
    cout << "-------------------------------------\n";
	{
		cout << "Check deep copy of Dog class using assignment operator overload:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog;

		*dogA = *dogB;
		delete dogA;
		delete dogB;
	}
	cout << "-------------------------------------\n";
	{
		cout << "Check deep copy of Cat class using copy constructor:\n" << endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat(*catA);

		delete catA;
		delete catB;
	}
	cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using assignment operator overload:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat;

		*catA = *catB;
		delete catA;
		delete catB;
	}
    return 0;
}
/*
- las copias de Dog y Cat no deben ser shallow(superficiales) sino deep copies(profundas)
En C++, los términos "shallow" (superficial) y "deep" (profundo) se utilizan comúnmente para describir cómo se manejan las copias de objetos, especialmente cuando estos objetos contienen punteros o referencias a otros recursos (como memoria asignada dinámicamente).

Aquí te explico la diferencia:

Copia Superficial (Shallow Copy)

Qué hace:
Una copia superficial copia los valores de los miembros de un objeto a otro.
Si el objeto contiene punteros, solo se copian los valores de los punteros, no los datos a los que apuntan.
Problemas:
Si dos objetos comparten el mismo puntero y uno de ellos modifica los datos a los que apunta, el otro objeto también se verá afectado.
Si uno de los objetos libera la memoria a la que apunta el puntero, el otro objeto tendrá un puntero colgante (un puntero que apunta a una ubicación de memoria que ya no es válida).
Copia Profunda (Deep Copy)

Qué hace:
Una copia profunda crea copias independientes de todos los recursos a los que apunta el objeto.
Si el objeto contiene punteros, se asigna nueva memoria y se copian los datos a los que apuntan los punteros.
Ventajas:
Cada objeto tiene su propia copia independiente de los datos, por lo que las modificaciones en un objeto no afectan a los demás.
Se evitan los problemas de punteros colgantes.
Cuando es necesaria:
Cuando un objeto contiene punteros a memoria dinámica.
Cuando se quiere que las copias de un objeto sean completamente independientes.
En resumen:

Una copia superficial es rápida pero puede llevar a problemas de memoria y datos compartidos.
Una copia profunda es más lenta pero garantiza la independencia de los objetos.
Ejemplo simplificado:

Imagina una clase que contiene un puntero a un array de enteros.

Copia superficial: Ambos objetos tendrían punteros que apuntan al mismo array.
Copia profunda: Cada objeto tendría su propio array independiente con los mismos valores.
*/