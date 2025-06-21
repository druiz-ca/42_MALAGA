/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 23:06:00 by ncolomer          #+#    #+#             */
/*   Updated: 2025/05/09 11:57:58 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include "ATarget.hpp"

using std::cout;
using std::endl;
using std::string;


class ATarget;

class ASpell
{
	private:
		string name;
		string effects;
	public:
		ASpell();
		ASpell(string const &name, string const &effects);
		ASpell(ASpell const &other);
		virtual ~ASpell();

		ASpell &operator=(ASpell const &other);

		string const &getName(void) const;
		string const &getEffects(void) const;

		void launch(ATarget const &target) const;

		virtual ASpell *clone(void) const = 0;
};


#endif
