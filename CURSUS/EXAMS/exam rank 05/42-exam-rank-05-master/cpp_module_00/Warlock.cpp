/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:37:13 by ncolomer          #+#    #+#             */
/*   Updated: 2025/05/08 12:13:38 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(string const &name, string const &title)
{
	this->name=name;
	this->title=title;
	cout << this->name << ": What a boring day\n";
}

Warlock::~Warlock() 
{
	cout << this->name << ": My job here is done!\n";
}

string const &Warlock::getName(void) const 
{
	return (this->name);
}

string const &Warlock::getTitle(void) const 
{
	return (this->title);
}

void Warlock::setTitle(string const &title) 
{
	this->title = title;
}

void Warlock::introduce(void) const 
{
	cout << this->name << ": My name is " << this->name << ", " << this->title << "!" << endl;
}
