/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:03:35 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/20 11:12:37 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// para que no se incluya más de 1 vez si se llama varias veces y no sobreescriba
#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

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
        void setGrade(int grade);
        void signForm(string name_form, bool isSigned);

        class GradeTooHighException : public exception
        {   // sino mo especifico que what es public no lo puedo usar
            public:
                virtual const char *what() const throw();
                // virtual para poder sobre escribirlo en las clases hijas
        };

        class GradeTooLowException : public exception
        {
            public:
                virtual const char *what() const throw();
        };
    
    private:
    //ahora uso name sin const para poderlo cambiar si quiero
        string Name;
        int Grade;
};

ostream &operator<<(ostream &o, const Bureaucrat &obj);

#endif