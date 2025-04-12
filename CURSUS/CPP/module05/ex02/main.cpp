/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:59:43 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/30 12:04:49 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp" 
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdio.h>


using std::cout;
using std::endl;
using std::cerr; 
using std::exception;

int main()
{
    Bureaucrat Pepe("Pepe", 1);
    Bureaucrat Juan("Juan", 4); 
    Bureaucrat Maria("Maria", 3);

    cout << endl;

    cout << "Creating forms: " << endl;

    ShrubberyCreationForm form1("form1");
    PresidentialPardonForm form2("form2");
    RobotomyRequestForm form3("form3");

    cout << endl;

    cout << "Signing and executing forms: " << endl;

    Pepe.executeForm(form1);
    form1.beSigned(Pepe);
    Pepe.executeForm(form1);
    
    cout << endl;
    
    Juan.executeForm(form2);
    form2.beSigned(Juan);
    Juan.executeForm(form2);
    
    cout << endl;

    Maria.executeForm(form3);
    form3.beSigned(Maria);
    Maria.executeForm(form3);


    cout << endl;

    cout << "Trying to execute forms with wrong grades: " << endl;

    try
    {
        Bureaucrat Juan("Juan", 150);
        Juan.executeForm(form1);
    }
    catch (exception &e)
    {
        cerr << e.what() << endl;
    }

    cout << endl;
    
}
