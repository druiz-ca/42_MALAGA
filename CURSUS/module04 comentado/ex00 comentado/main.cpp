/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:18:15 by daniel            #+#    #+#             */
/*   Updated: 2025/03/01 10:17:46 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
//#include "WrongAnimal.hpp" POR LLAMARLO MAS DE UNA VEZ DABA ERROR!!!!
#include "WrongCat.hpp"

using std::cout;
using std::endl;

int main()
{
    //cuando se crea un objeto con new se pone * porque es un puntero
    //si no se pone * se crea un objeto normal
    const Animal *meta = new Animal(); // creado en el heap que es
    // la memoria dinamica y se accede con punteros
    // recordar que new es como malloc entonces se debe liberar la memoria
    const Animal *i = new Dog();
    const Animal *j = new Cat();
    
    const WrongAnimal *k = new WrongCat();
    const WrongCat *l = new WrongCat();
    // cuando lo creo asi: Animal("gato") es como en C Animal[1] = "gato"
    
    cout << j->getType() << " " << endl;
    cout << i->getType() << " " << endl;
    
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    k->makeSound();
    l->makeSound();

    // cuando creo un puntero a un objeto con new tengo que 
    // liberar la memoria con delete y delete se encarga
    // de llamar al destructor del objeto
    delete meta;
    delete i;
    delete j;
    delete k;
    delete l;

    cout << k->getType() << " " << endl;

}