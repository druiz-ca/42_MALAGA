/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:59:43 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/24 11:58:10 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
    cout << "-------- grade 0 signature form" << endl;
    try
    {
        Form f("Form1", 0, 50); // Crear un formulario con grado para firmar y ejecutar 66
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl; // Imprimir la excepción
    }
    cout << endl;

    
    cout << "-------- grade 0 execution form" << endl;
    try
    {
		Form f("Fomr2", 50, 0);		
	} 
    catch (std::exception &e)
    {
		cerr << e.what() << endl;
	}
    cout << endl;


    cout << "-------- grade 151 signature form" << endl;
    try {
		Form f("form3", 151, 50);		
	} catch (std::exception &e) {
		cerr << e.what() << endl;	
	}
    cout << endl;


    cout << "-------- grade 151 execution form" << endl;
	try {
		Form B("Form4", 151, 0);		
	} catch (std::exception &e) {
		cerr << e.what() << endl;	
	}
    cout << endl;

    cout << "-------- grade 50 form signed by grade 100 bureaucrat" << endl;
    try {
        Form f("Form5", 50, 50);		
        Bureaucrat b("pepe", 11);	
        // pruebo sobrecarga de operador <<
        cout << f << endl;
        cout << b << endl;
        f.beSigned(b);					
    } catch (std::exception &e) {
        cerr << e.what() << endl;	
    }
    cout << endl;


    cout << "-------- grade 50 form signed by grade 100 bureaucrat" << endl;
    try {
        Form f("Form6", 50, 50);		
        Bureaucrat b("Jose", 10);	
        cout << f << endl;
        cout << b << endl;
        
        // Intentar firmar el formulario con un burócrata de grado 10		
        f.beSigned(b);
        cout << f << endl;
    } 
    catch (std::exception &e)
    {
        cerr << e.what() << endl;	
    }    
}