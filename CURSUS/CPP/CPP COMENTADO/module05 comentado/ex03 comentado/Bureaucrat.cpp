/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:03:24 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/24 12:01:43 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

using std::string;
using namespace std;

Bureaucrat::Bureaucrat()
{
    // por defecto el grado es el más bajo = 150
    this->Grade = LOWEST;
    this->Name = "Default"; // como Name ya no es const lo puedo inicializar aquí
    cout << "Default Bureaucrat Constructor Called" << endl;
}

// como Name es constante solo se puede inicializar en la lista de inicialización, despues no se puede
Bureaucrat::Bureaucrat(string Name, int Grade)
{
    this->Name = Name;
    if (Grade < HIGHEST) // 1
    {
        // no necesita especificar la clase porque está anidada en bureucrat
        throw AForm::GradeTooHighException(); // lanzamos la excepción
    }
    if (Grade > LOWEST)
        throw AForm::GradeTooLowException();
    // si no se lanza la excepción, entonces se asigna el grado
    this->Grade = Grade;
    cout << "Parameter Constructor is Called" << endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copybureaucrat) 
{
    // si no es el mismo objeto, entonces se copia
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
    // no necesita else porque el throw corta la ejecución
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