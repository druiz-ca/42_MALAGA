/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:12:17 by daniel            #+#    #+#             */
/*   Updated: 2025/03/30 12:33:31 by druiz-ca         ###   ########.fr       */
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
    (void)copy;
    cout << "Intern overload operator = is called" << endl;
    return *this;
}

AForm *Intern::makeForm(const string &name, const string &target)
{
	AForm *document;
	
	document = AForm::makeForm(name, target);
	if (!document)
		throw ErrorForm();
	cout << "Intern create a form: " << name << " with target: " << document->getTarget() << endl;
	return (document);
}   