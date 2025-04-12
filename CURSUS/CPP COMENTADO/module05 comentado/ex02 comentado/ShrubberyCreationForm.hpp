/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:47:29 by daniel            #+#    #+#             */
/*   Updated: 2025/03/23 12:55:03 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &assign);
        void executeSuperClassForm(Bureaucrat const &executor) const;

    private:
        ShrubberyCreationForm();
};