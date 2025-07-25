/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:37:27 by ncolomer          #+#    #+#             */
/*   Updated: 2025/05/08 12:41:00 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;

class Warlock
{
	private:
		string name;
		string title;

		//Warlock();
		//Warlock(Warlock const &other);

		//Warlock &operator=(Warlock const &other);
	public:
		Warlock(string const &name, string const &title);
		virtual ~Warlock();

		string const &getName(void) const;
		string const &getTitle(void) const;

		void setTitle(string const &title);
		void introduce(void) const;
};

#endif
