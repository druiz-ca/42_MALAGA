/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:59:43 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/17 20:27:32 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* EXCEPCIONES
    try: intenta ejecutar el bloque de código que sigue a continuación.
    catch: captura una excepción y ejecuta el bloque de código que sigue a continuación.    
*/

using std::cout;
using std::endl;
using std::cerr; // objeto de flujo de salida para imprimir mensajes de error en la pantalla.
using std::exception;

int main()
{
    try
    {
        Bureaucrat pepe("pepe", 0);
        // como el grado es 0, lanza la excepción y ya no imprime la siguiente linea
        cout << pepe << endl;
    }
    //POLIMORFISMO:
    // exception captura la excepcion pq gradetoohigh... hereda de exception
    catch (exception &e) // el objeto exceotion se crea por referencia para evitar copias innecesarias
    { // los try y catch llevan llaves aunque solo tenga 1 linea
        cout << e.what() << endl;
    }

    try
    {
        Bureaucrat lola("lola", 151);
        cout << lola << endl;
    }
    // cuando creo el objeto con exception imprime el mensaje que he especificado
    // en el método de la escepción correspondiente
    catch (exception &e)
    {   // con excepcion si puedo usar e.what() aunque sea privado ?!?!
        cout << e.what() << endl;
    }

    try
    {
        Bureaucrat jose("jose", 1);
        cout << jose << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

    // ------ HAY OTRA FORMA DE HACERLO USANDO MI EXCEPCION PERSONALIZADA ------
    try
	{
        Bureaucrat bureaucrat("pepe2", 151);
        cout << bureaucrat << endl;
    }
    // cuando creo el objeto directamente con el nombre de la excepción imprime
    // el mensaje del cerr no el del método de la excepción?!?! lo pisa!
    catch (Bureaucrat::GradeTooHighException &e) 
	{   // en vez de cout usamos cerr para imprimir errores
        //cerr << "TooHighException" << endl;
        // si intento imprimir el mensaje con e.what() da error!?
        cout << e.what() << endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
	{
        cout << e.what() << endl;
    }

}