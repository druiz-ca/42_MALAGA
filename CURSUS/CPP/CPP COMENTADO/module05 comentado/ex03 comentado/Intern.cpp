/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:12:17 by daniel            #+#    #+#             */
/*   Updated: 2025/03/29 13:46:06 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

using namespace std;

Intern::Intern()
{
    cout << "Intern default constructor is called" << endl;
}

Intern::Intern(const Intern &src)
{
    cout << "Intern Copy constructor is called" << endl;
    *this = src;
}

Intern::~Intern()
{
    cout << "Intern Destrcutor is called" << endl;
}

Intern &Intern::operator=(const Intern &copy)
{
    (void)copy; // solo para que no de error por no usar copy!!
    cout << "Intern overload operator = is called" << endl;
    return *this;
}

// en cada clase, el makeForm hace una cosa diferente
AForm *Intern::makeForm(const string &name, const string &target)
{
	AForm *document;
	
    // no hace bucle pq aunque se llamen igual son de clases diferentes!!!
	document = AForm::makeForm(name, target);
	if (!document)
		throw ErrorForm();
	cout << "Intern create a form: " << name << " with target: " << document->getTarget() << endl;
	return (document);
}   