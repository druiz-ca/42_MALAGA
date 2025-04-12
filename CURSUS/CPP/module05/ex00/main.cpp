/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:59:43 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/16 14:31:50 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::cerr;
using std::exception;

int main()
{
    try
    {
        Bureaucrat pepe("pepe", 0);
        cout << pepe << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        Bureaucrat lola("lola", 151);
        cout << lola << endl;
    }
    
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        Bureaucrat jose("jose", 1);
        cout << jose << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

    try 
	{
        Bureaucrat bureaucrat("pepe2", 1515);
        cout << bureaucrat << endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) 
	{   
        cout << e.what() << endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
	{
        cout << e.what() << endl;
    }

}