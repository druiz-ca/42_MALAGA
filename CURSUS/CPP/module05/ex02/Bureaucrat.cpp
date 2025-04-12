/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:03:24 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/30 12:03:50 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

using std::string;
using namespace std;

Bureaucrat::Bureaucrat()
{
    this->Grade = LOWEST;
    this->Name = "Default";
    cout << "Default Bureaucrat Constructor Called" << endl;
}

Bureaucrat::Bureaucrat(string Name, int Grade)
{
    this->Name = Name;
    if (Grade < HIGHEST) // 1
    {
        throw AForm::GradeTooHighException();
    }
    if (Grade > LOWEST)
        throw AForm::GradeTooLowException();
    this->Grade = Grade;
    cout << "Parameter Constructor is Called" << endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copybureaucrat) 
{
    if (this != &copybureaucrat)
        *this = copybureaucrat;
    cout << "Copy Constructor is Called" << endl;
}

Bureaucrat::~Bureaucrat() 
{
    cout << "Destructor is called" << endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &copybureaucrat) 
{
    this->Grade = copybureaucrat.Grade;
    this->Name = copybureaucrat.Name;
    cout << "Overloading asignation Operator is called" << endl;
    return *this;
}

ostream &operator<<(ostream &stream, Bureaucrat const & object) 
{
    stream << object.getName() << ", bureaucrat grade " << object.getGrade() << endl;
    cout << "Overloading << Operator is called" << endl;
    return stream;
}

string Bureaucrat::getName() const 
{
    return this->Name;
}

int Bureaucrat::getGrade() const 
{
    return this->Grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->Grade == HIGHEST)
        throw AForm::GradeTooHighException();
    this->Grade--;
}

void Bureaucrat::decrementGrade() 
{
    if (this->Grade == LOWEST)
        throw AForm::GradeTooLowException();
    this->Grade++;
}

void Bureaucrat::setGrade(int _grade) 
{
    if (_grade < HIGHEST)
        throw AForm::GradeTooHighException();
    if (_grade > LOWEST)
        throw AForm::GradeTooLowException();
    this->Grade = _grade;
}

void Bureaucrat::signForm(string name_form, bool isSigned) 
{
    if (isSigned)
        cout << this->Name << " signs " << name_form << endl;
    else
        cout << this->Name << " cannot sign " << name_form << endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Invalid: Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Invalid: Grade is too low";
}

void Bureaucrat::executeForm(AForm const &form) 
{
    form.execute(*this);
}