/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:03:24 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/20 10:24:00 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

using std::string;

Bureaucrat::Bureaucrat():Name("no name") 
{
    // por defecto el grado es el más bajo = 150
    this->Grade = LOWEST;
}

// como Name es constante solo se puede inicializar en el momento de inicialización, despues no se puede!!!!
Bureaucrat::Bureaucrat(string Name, int Grade): Name(Name)
{
    if (Grade < HIGHEST)
        throw Bureaucrat::GradeTooHighException(); // lanzamos la excepción
    if (Grade > LOWEST)
        throw  Bureaucrat::GradeTooLowException();
    // si no se lanza la excepción, entonces se asigna el grado
    this->Grade = Grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) 
{
    *this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & object) 
{
    if (object.Grade < HIGHEST)
        throw Bureaucrat::GradeTooHighException();
    if (object.Grade > LOWEST)
        throw  Bureaucrat::GradeTooLowException();
    this->Grade = object.Grade;
    return *this;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & object) 
{
    o << object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
    return o;
}

std::string Bureaucrat::getName() const 
{
    return this->Name;
}

int Bureaucrat::getGrade() const 
{
    return this->Grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->Grade - 1 < HIGHEST)
        throw Bureaucrat::GradeTooHighException();
    this->Grade--;
}

void Bureaucrat::decrementGrade() 
{
    if (this->Grade + 1 > LOWEST)
        throw Bureaucrat::GradeTooLowException();
    this->Grade++;
}

//sobreescribo el método what() de la clase base exception para personalizar el mensaje
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Invalid: Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Invalid: Grade is too low";
}

const char *exception::what() const throw()
{
    return "prueba";
}