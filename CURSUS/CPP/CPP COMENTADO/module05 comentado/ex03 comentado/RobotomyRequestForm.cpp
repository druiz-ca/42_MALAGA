/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:57:20 by daniel            #+#    #+#             */
/*   Updated: 2025/03/30 11:45:33 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>
#include <stdio.h>

using namespace std;

RobotomyRequestForm::RobotomyRequestForm(string target) : AForm("RobotomyRequestForm", target, 72, 45)
{
    cout << "RobotomyRequestForm parametric constructor called" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src.getName(), src.getTarget(), src.getGradeToSign(), src.getGradeToExecute())
{
    cout << "RobotomyRequestForm copy constructor called" << endl;
    *this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    (void)src; // solo para que no de error por no usar src!!
    cout << "RobotomyRequestForm assignation operator called" << endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    cout << "RobotomyRequestForm destructor called" << endl;
}

void RobotomyRequestForm::executeMain(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw Bureaucrat::GradeTooLowException(); 
    else if (!this->getSigned() == false)
        cerr << executor.getName() << " cannot execute " << this->getName() << " because the form is not signed" << endl;
    else
    {
        // sirve para que el random una secuencia de numeros diferentes cada vez que se ejecute
        srand(time(NULL));
            // time(NULL) devuelve el tiempo en segundos desde el 1 de enero de 1970
        // para que el robotomizado sea aleatorio el 50% de las veces
        if (random() % 2 == 0)
            cout << this->getTarget() << " has been robotomized successfully" << endl;
        else
            cout << this->getTarget() << " has not been robotomized successfully" << endl;
    }
}

AForm *RobotomyRequestForm::makeForm(AForm *document, const string &name, const string &target)
{
    if (document == NULL && name == "robotomy request")
        return (new RobotomyRequestForm(target));
    return (document);
}