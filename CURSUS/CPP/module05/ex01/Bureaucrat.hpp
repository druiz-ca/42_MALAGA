/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:03:35 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/30 12:01:36 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

#include <iostream>

using namespace std;

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
        string Name;
        int Grade;
};

ostream &operator<<(ostream &o, const Bureaucrat &obj);

#endif