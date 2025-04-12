/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:59:43 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/30 12:33:55 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp" // el orden en que enlazo los archivos es importante!!!!
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>

using std::cout;
using std::endl;
using std::cerr;
using std::exception;

int main()
{
    Intern pepe;
    
    AForm *f;
    Bureaucrat jose("Jose", 1);

    try
    {
        f = pepe.makeForm("robotomy request", "antonio");
        delete f;
        cout << "------------------------------------" << endl;
        f = pepe.makeForm("shrubbery creation", "manolo");
        delete f;
        cout << "------------------------------------" << endl;
        f = pepe.makeForm("presidential pardon", "lola");
        delete f;
        cout << "------------------------------------" << endl;
        f = pepe.makeForm("error", "lolita");
        delete f;
    }
    catch(const exception& e)
    {
        cerr << e.what() << endl;
    }

    cout << "------------------------------------" << endl;
    f = pepe.makeForm("shrubbery creation", "jose");
    try
    {
        f->beSigned(jose);
    }
    catch(const exception& e)
    {
        cerr << "Error: the grade is not correct" << endl;
        exit(1);
    }
    jose.executeForm(*f);
    delete f;
    
}