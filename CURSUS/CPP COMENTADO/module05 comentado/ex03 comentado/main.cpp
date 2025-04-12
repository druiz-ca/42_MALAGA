/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:59:43 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/30 11:25:33 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp" // el orden en que enlazo los archivos es importante!!!!
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>

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
    Intern pepe;
    
    // se necesita el puntero para solo para poder liberar la memoria (por usar new)
    AForm *f;
    Bureaucrat jose("Jose", 1);

    try
    {
        
        // el primer argumento es el nombre identificador del formulario 
        // el segundo el nombre del destinatario
        f = pepe.makeForm("robotomy request", "antonio");
        delete f;
        cout << "------------------------------------" << endl;
        f = pepe.makeForm("shrubbery creation", "manolo");
        delete f;
        cout << "------------------------------------" << endl;
        f = pepe.makeForm("presidential pardon", "lola");
        delete f;
        cout << "------------------------------------" << endl;
        f = pepe.makeForm("error", "lolita");
        delete f;
    }
    catch(const exception& e)
    {
        cerr << e.what() << endl;
    }

    cout << "------------------------------------" << endl;
    f = pepe.makeForm("shrubbery creation", "jose");
    try
    {
        // pruebo a firmar y ejecutar el fomrulario con un buocrata
        f->beSigned(jose);
    }
    catch(const exception& e)
    {
        cerr << "Error: the grade is not correct" << endl;
        exit(1);
    }
    // si no ha dado error firmando el formulario, lo ejecuto
    jose.executeForm(*f);
    delete f;
    
}

/*
ERRORES:
    - cuando da este error: /usr/bin/ld: AForm.o: in function `AForm::AForm(AForm&)':
    AForm.cpp:(.text+0x50): undefined reference to `AForm::getTarget[abi:cxx11]() const'
    es porque no se ha implenetado esa funcion que dice "undefined"....
*/