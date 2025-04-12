/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:37:04 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/30 12:32:16 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

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

        static AForm *makeForm(const string &name, const string &target);
        
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
        const int gradeToSign;
        const int gradeToExecute;
        bool isSigned;
        virtual void executeMain(Bureaucrat const &executor) const = 0;
};

ostream &operator<<(ostream &stream, AForm const &object);

#endif