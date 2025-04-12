/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:59:43 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/03/30 12:02:14 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

using std::cout;
using std::endl;
using std::cerr;
using std::exception;

int main()
{
    cout << "-------- grade 0 signature form" << endl;
    try
    {
        Form f("Form1", 0, 50);
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
    }
    cout << endl;

    
    cout << "-------- grade 0 execution form" << endl;
    try
    {
		Form f("Fomr2", 50, 0);		
	} 
    catch (std::exception &e)
    {
		cerr << e.what() << endl;
	}
    cout << endl;


    cout << "-------- grade 151 signature form" << endl;
    try {
		Form f("form3", 151, 50);		
	} catch (std::exception &e) {
		cerr << e.what() << endl;	
	}
    cout << endl;


    cout << "-------- grade 151 execution form" << endl;
	try {
		Form B("Form4", 151, 0);		
	} catch (std::exception &e) {
		cerr << e.what() << endl;	
	}
    cout << endl;

    cout << "-------- grade 50 form signed by grade 100 bureaucrat" << endl;
    try {
        Form f("Form5", 50, 50);		
        Bureaucrat b("pepe", 11);	

        cout << f << endl;
        cout << b << endl;
        f.beSigned(b);					
    } catch (std::exception &e) {
        cerr << e.what() << endl;	
    }
    cout << endl;


    cout << "-------- grade 50 form signed by grade 100 bureaucrat" << endl;
    try {
        Form f("Form6", 50, 50);		
        Bureaucrat b("Jose", 10);	
        cout << f << endl;
        cout << b << endl;
        
        f.beSigned(b);
        cout << f << endl;
    } 
    catch (std::exception &e)
    {
        cerr << e.what() << endl;	
    }    
}