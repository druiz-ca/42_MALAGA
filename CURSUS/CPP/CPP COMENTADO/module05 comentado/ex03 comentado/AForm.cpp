/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:36:55 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/30 11:44:54 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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
    this->executeMain(executor);
}

/* esta función que deriva al método makeForma personalizado para cada caso
 - si el makForm al que llama devuelve algo que no sea NULL es que ha creado
 ese formulario y lo devuelve.
 // se pueden cambiar los parametros del metodo makeForm porque
 // es virtual: el de AForm es de una forma y los otros de otra
*/ 
AForm *AForm::makeForm(string const &formName, string const &target)
{                                       // target es al destinatario
    // lo establezco en NULL para poder ir controlando si alguien ha creado el form
    AForm *document = NULL;
    document = PresidentialPardonForm::makeForm(document, formName, target);
    document = RobotomyRequestForm::makeForm(document, formName, target);
    document = ShrubberyCreationForm::makeForm(document, formName, target);
    return document;
}