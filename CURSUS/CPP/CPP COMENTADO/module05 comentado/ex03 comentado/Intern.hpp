/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:12:10 by daniel            #+#    #+#             */
/*   Updated: 2025/03/25 11:23:58 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

using namespace std;

class Intern
{
    public:
        Intern();
        Intern(const Intern &src);
        ~Intern();
        
        Intern &operator=(const Intern &copy);
        AForm *makeForm(const string &name, const string &target);

        class ErrorForm : public exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Error: Form not found");
                }
        };
};