/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:37:04 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/23 14:29:03 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

//no tengo que volver a incluir namespace std porque ya lo tengo en Bureaucrat.hpp
//  #include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

using namespace std;

class AForm
{
    public:
        AForm(string name, string target, int gradeToSign, int gradeToExecute);
        AForm(AForm &src);
        virtual ~AForm();
        
        AForm &operator=(const AForm &src);    
        const string &getName() const;
        const string &getTarget() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getSigned() const;
        void beSigned(Bureaucrat &bureaucrat);
        void execute(Bureaucrat const &executor) const;
        
        class GradeTooHighException : public exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public exception
        {
            public:
                virtual const char *what() const throw();
        };
        
    private:

        const string name;
        const string target;
        // isSigned no es const porque va cambiando durante la ejcucion
        const int gradeToSign;
        const int gradeToExecute;
        bool isSigned;
        virtual void executeSuperClassForm(Bureaucrat const &executor) const = 0;
        //el const = 0 es para que sea una funcion virtual pura, es decir, 
        //una funcion que no tiene implementacion en la clase base y que debe
        // ser implementada en las clases derivadas. 
};

ostream &operator<<(ostream &stream, AForm const &object);

#endif