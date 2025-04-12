/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:36:55 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/21 11:40:26 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

using namespace std;

// como name es const tengo que inicializarlo en la lista de inicialización
Form::Form(const Form &copy) : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{
    cout << "The form " << this->getName() << " has been copied." << endl;
}

Form::Form(string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < HIGHEST || gradeToExecute < HIGHEST)
        throw GradeTooHighException();
    if (gradeToSign > LOWEST || gradeToExecute > LOWEST)
        throw GradeTooLowException();
    cout << "Form " << this->getName() << " created with grade to sign " << this->getGradeToSign() << " and grade to execute " << this->getGradeToExecute() << endl;
    this->isSigned = false; // por defecto no está firmado
}

Form::~Form()
{
    cout << "The form " << this->getName() << " has been destroyed." << endl;
}

// tiene que devolver el objeto por referencia para poder encadenar asignaciones
Form &Form::operator=(const Form &copy)
{   // la única var que no es const es copy x eso se puede copiar/modificar
    if (this != &copy)
        this->isSigned = copy.isSigned;
    return *this;
}

ostream &operator<<(ostream &stream, Form const &object)
{
    stream << "Form " << object.getName() << " with grade to sign " << object.getGradeToSign() << " and grade to execute " << object.getGradeToExecute() << " is ";
    if (object.getSigned())
        stream << "signed.";
    else
        stream << "not signed.";
    return stream;
}

const string &Form::getName() const
{
    return this->name;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}

bool Form::getSigned() const
{
    return this->isSigned;
}

void Form::beSigned(Bureaucrat &bureaucrat)
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
        throw GradeTooLowException();
    }
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Error: Grade is too low.";
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Error: Grade is too high.";
}