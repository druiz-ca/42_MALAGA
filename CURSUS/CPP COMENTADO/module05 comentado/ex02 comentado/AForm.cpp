/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:36:55 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/24 12:34:44 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <stdio.h>

using namespace std;

// como name es const tengo que inicializarlo en la lista de inicialización
AForm::AForm(AForm& src) : name(src.getName()), target(src.getTarget()), gradeToSign(src.getGradeToSign()), gradeToExecute(src.getGradeToExecute()), isSigned(src.getSigned())
{
    cout << "AForm: copy constructor called" << endl;
}

AForm::AForm(string name, string target, int gradeToSign, int gradeToExecute) : name(name), target(target), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(false)
{
    if (gradeToSign < HIGHEST || gradeToExecute < HIGHEST)
        throw AForm::GradeTooHighException();
    if (gradeToSign > LOWEST || gradeToExecute > LOWEST)
        throw AForm::GradeTooLowException();
    cout << "Form " << this->getName() << " created with grade to sign " << this->getGradeToSign() << " and grade to execute " << this->getGradeToExecute() << endl;
    this->isSigned = false; // por defecto no está firmado
}   

AForm::~AForm()
{
    cout << "The form " << this->getName() << " has been destroyed." << endl;
}

// tiene que devolver el objeto por referencia para poder encadenar asignaciones
AForm &AForm::operator=(const AForm &copy)
{   // la única var que no es const es copy x eso se puede copiar/modificar
    if (this != &copy)
        this->isSigned = copy.isSigned;
    return *this;
}

ostream &operator<<(ostream &stream, AForm const &object)
{
    stream << "Form " << object.getName() << " with grade to sign " << object.getGradeToSign() << " and grade to execute " << object.getGradeToExecute() << " is ";
    if (object.getSigned())
        stream << "signed.";
    else
        stream << "not signed.";
    return stream;
}

const string &AForm::getName() const
{
    return this->name;
}

const string &AForm::getTarget() const
{
    return this->target;
}

int AForm::getGradeToSign() const
{
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->gradeToExecute;
}

bool AForm::getSigned() const
{
    return this->isSigned;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getGradeToSign())
    {
        this->isSigned = true;
        bureaucrat.signForm(this->getName(), this->isSigned);
        cout << "The form " << this->getName() << " has been signed by " << bureaucrat.getName() << endl;
    }
    else
    {
        cout << "The form " << this->getName() << " has not been signed by " << bureaucrat.getName() << endl;
        throw AForm::GradeTooLowException();
    }
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Error: Grade is too low.";
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Error: Grade is too high.";
}

void AForm::execute(Bureaucrat const &executor) const
{
    this->executeSuperClassForm(executor);
}