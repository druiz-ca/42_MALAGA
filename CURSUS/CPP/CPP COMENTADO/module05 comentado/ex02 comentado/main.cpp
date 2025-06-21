/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:59:43 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/24 12:34:19 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp" // el orden en que enlazo los archivos es importante!!!!
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdio.h>

/* EXCEPCIONES
    try: intenta ejecutar el bloque de código que sigue a continuación.
    catch: captura una excepción y ejecuta el bloque de código que sigue a continuación.    

- la idea es que el formilario tenga un grado minimo para firmar y otro para ejecutar

*/

using std::cout;
using std::endl;
using std::cerr; // objeto de flujo de salida para imprimir mensajes de error en la pantalla.
using std::exception;

int main()
{
    Bureaucrat Pepe("Pepe", 1);
    Bureaucrat Juan("Juan", 4); // cuando tiene menos rango que el doc peta
    Bureaucrat Maria("Maria", 3);

    cout << endl;

    cout << "Creating forms: " << endl;

    ShrubberyCreationForm form1("form1");//145, 137
    PresidentialPardonForm form2("form2");//25, 5
    RobotomyRequestForm form3("form3");//72, 45

    cout << endl;

    cout << "Signing and executing forms: " << endl;

    Pepe.executeForm(form1);
    form1.beSigned(Pepe);
    Pepe.executeForm(form1);
    
    cout << endl;
    
    Juan.executeForm(form2);
    form2.beSigned(Juan);
    Juan.executeForm(form2);
    
    cout << endl;

    Maria.executeForm(form3);
    form3.beSigned(Maria);
    Maria.executeForm(form3);


    cout << endl;

    cout << "Trying to execute forms with wrong grades: " << endl;

    try
    {
        Bureaucrat Juan("Juan", 150);
        Juan.executeForm(form1);
    }
    catch (exception &e)
    {
        cerr << e.what() << endl;
    }

    cout << endl;
    
}

/*
ERRORES:
    - cuando da este error: /usr/bin/ld: AForm.o: in function `AForm::AForm(AForm&)':
    AForm.cpp:(.text+0x50): undefined reference to `AForm::getTarget[abi:cxx11]() const'
    es porque no se ha implenetado esa funcion que dice "undefined"....
*/