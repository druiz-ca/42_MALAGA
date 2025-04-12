/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:36:55 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/30 12:35:42 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <stdio.h>

using namespace std;

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
    this->isSigned = false;
}   

AForm::~AForm()
{
    cout << "The form " << this->getName() << " has been destroyed." << endl;
}

AForm &AForm::operator=(const AForm &copy)
{ 
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