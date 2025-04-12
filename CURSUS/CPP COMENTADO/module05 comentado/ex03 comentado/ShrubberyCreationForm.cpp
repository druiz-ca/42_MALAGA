/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:46:34 by daniel            #+#    #+#             */
/*   Updated: 2025/03/30 13:38:22 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

using namespace std;
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(string target) : AForm("ShrubberyCreationForm", target, 145, 137)
{
    cout << "ShrubberyCreationForm parametric constructor called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src.getName(), src.getTarget(), src.getGradeToSign(), src.getGradeToExecute())
{
    cout << "ShrubberyCreationForm copy constructor called" << endl;
    *this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    (void)src; // solo para que no de error por no usar src!!
    cout << "ShrubberyCreationForm assignation operator called" << endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    cout << "ShrubberyCreationForm destructor called" << endl;
}

void ShrubberyCreationForm::executeMain(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();
    else if (this->getSigned() == false)
        cerr << executor.getName() << " cannot execute " << this->getName() << " because the form is not signed" << endl;
    else
    {
        ofstream out; // objeto de flujo de salida para escribir en archivos

        out.open((this->getTarget() + "_shrubbery").c_str(), ofstream::in | ofstream::trunc);
        // c_str convierte la cadena de carácteres en puntero *char(que es lo que espera open)
        // in: abre el archivo para lectura
        // trunc: borra el contenido del archivo si ya existe
        
        out << "\n";
        out << "    *" << endl;
        out << "   ***" << endl;
        out << "  *****" << endl;
        out << " *******" << endl;
        out << "*********" << endl;
        out << "    |" << endl;
        out << "    |" << endl;
    }
}

AForm *ShrubberyCreationForm::makeForm(AForm *document, const string &name, const string &target)
{
    if (document == NULL && name == "shrubbery creation")
        return (new ShrubberyCreationForm(target));
    return (document);
}