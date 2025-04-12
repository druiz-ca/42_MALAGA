/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonform.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:45:52 by daniel            #+#    #+#             */
/*   Updated: 2025/03/30 12:09:30 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

using namespace std;

PresidentialPardonForm::PresidentialPardonForm(string target) : AForm("PresidentialPardonForm", target, 25, 5)
{
    cout << "PresidentialPardonForm parametric constructor called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src.getName(), src.getTarget(), src.getGradeToSign(), src.getGradeToExecute())
{
    cout << "PresidentialPardonForm copy constructor called" << endl;
    *this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    cout << "PresidentialPardonForm assignation operator called" << endl;
    (void)src;
    return *this;
}

void PresidentialPardonForm::executeMain(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();
    else if (this->getSigned() == false)
        cerr << executor.getName() << " cannot execute " << this->getName() << " because the form is not signed" << endl;
    else
        cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    cout << "PresidentialPardonForm destructor called" << endl;
}