/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:03:35 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/17 20:23:01 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
- clase de excepcion personalizada 

- std::exception es una clase base para excepciones estándar 
que viene con la biblioteca estándar de C++.

- ENCAPSULACION: definimos una clase dentro de otra clase.
    sirve para expecificar que esa excepcion es solo para esa clase
*/
using namespace std;
// el using namespace sirve para todos los objetos de la libreria std

#define LOWEST 150
#define HIGHEST 1

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(string name, int grade);
        Bureaucrat(const Bureaucrat &src);
        ~Bureaucrat();

        Bureaucrat &operator=(const Bureaucrat &obj);

        string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        // creo una clase que herede de exception para personalizar el mensaje
        // pisando el método what() de la clase base
        class GradeTooHighException : public exception
        {   // sino no especifico publoc por defecto es privado!!!!
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public exception
        {
            public:
                const char *what() const throw();
        };
    
    private:
        const string Name;
        int Grade;
};

ostream &operator<<(ostream &o, const Bureaucrat &obj);