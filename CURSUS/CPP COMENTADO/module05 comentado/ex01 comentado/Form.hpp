/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:37:04 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/21 11:41:09 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

//no tengo que volver a incluir namespace std porque ya lo tengo en Bureaucrat.hpp
//  #include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    public:
        Form(string name, int gradeToSign, int gradeToExecute);
        Form(const Form &src);
        ~Form();
        
        Form &operator=(const Form &src);    
        const string &getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getSigned() const;
        void beSigned(Bureaucrat &bureaucrat);
        
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
        // isSigned no es const porque va cambiando durante la ejcucion
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
};

ostream &operator<<(ostream &stream, Form const &object);

#endif