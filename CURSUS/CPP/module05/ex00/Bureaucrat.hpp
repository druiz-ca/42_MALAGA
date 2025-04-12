/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:03:35 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/16 14:32:32 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

        class GradeTooHighException : public exception
        { 
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