/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:47:29 by daniel            #+#    #+#             */
/*   Updated: 2025/03/30 11:45:48 by druiz-ca         ###   ########.fr       */
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
        void executeMain(Bureaucrat const &executor) const;
        static AForm	*makeForm(AForm *document, std::string const &form, std::string const &target);

    private:
        ShrubberyCreationForm();
};