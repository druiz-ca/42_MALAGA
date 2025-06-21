/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:57:28 by daniel            #+#    #+#             */
/*   Updated: 2025/04/02 17:44:06 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"


Base *generate(void)
{   //SRAND INICIALIZA LA SEMILLA PARA QUE RAND() DEVUELVA UN NUMERO ALEATORIO
    // para generar un número aleatorio
    // unsigned por si el tiempo es negativo
    // NULL porque no se puede devolver un puntero nulo
    srand((unsigned)time(NULL));
    // rand() % 3 devuelve un número entre 0 y 2 para los 3 tipos de clase
    // los posibles residuos de dividir entre 3 solo son 0, 1 y 2 ?!
    switch (int num = rand() % 3) 
    {
        case 0: 
            return (new A());
        case 1: 
            return (new B());
        case 2: 
            return (new C());
        // si no coincide con ninguno de los 3: default-> devuelve NULL
        default: return (NULL);
    }
}

void identify(Base *p)
{
    // dynamic cast para identificar el tipo de objeto que es p
    if (dynamic_cast<A*>(p))
        cout << "The object is of type A" << endl;
    else if (dynamic_cast<B*>(p))
        cout << "The object is of type B" << endl;
    else if (dynamic_cast<C*>(p))
        cout << "The object is of type C" << endl;
    else
        cout << "Unknown type" << endl;
}

/* no permite indetificarlo igual que en el método que recibe por parámetro un
puntero, usando un puntero que apunte al valor referenciado por eso se usa try...*/
void identify(Base &p)
{ 
    try
    {
        (void) dynamic_cast<A&>(p);
        cout << "The object is of type A" << endl;
    }
    catch (exception &e)
    {
        try
        {
            (void) dynamic_cast<B&>(p);
            cout << "The object is of type B" << endl;
        }
        catch (exception &e)
        {
            try
            {
                (void) dynamic_cast<C&>(p);
                cout << "The object is of type C" << endl;
            }
            catch (exception &e)
            {
                cout << "Unknown type" << endl;
            }
        }
    }
}

int main()
{
    Base *p;
    for (int i = 0; i < 4; i++)
    {
        p = generate();
        identify(p); // llama a la función con puntero
        identify(*p); // llama a la función con referencia
        // tiene que hacer delete porque se le asigna memoria con new en generate
        delete p;
        cout << endl;
        sleep(1); // para que se vea el cambio de número
    }
    // prueba con un puntero nulo
    Base *c = NULL;
    if (c != NULL) {
        identify(*c);
    } else { // si el puntero es NULL no se puede identificar con el metodo de referencia!!
        cout << "Pointer is NULL, cannot identify." << endl;
    }
}