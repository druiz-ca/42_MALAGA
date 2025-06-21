/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:57:32 by daniel            #+#    #+#             */
/*   Updated: 2025/03/30 11:45:38 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(string target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(const RobotomyRequestForm &assign);
        void executeMain(Bureaucrat const &executor) const;
   		static AForm	*makeForm(AForm *document, std::string const &form, std::string const &target);

    private:
        RobotomyRequestForm();
};