#pragma once
#include <iostream>
#include <map>
#include "SpellBook.hpp"

using namespace std;

class ASpell;
class ATarget;

class Warlock
{
	public:
		Warlock(const string& name, const string& title);
		~Warlock();

		const string& getName() const;
		const string& getTitle() const;
		void setTitle(const string& title);
		void introduce() const;

		void learnSpell(ASpell*);
		void forgetSpell(string);
		void launchSpell(string, ATarget&);

	private:
		string _name;
		string _title;
		SpellBook _spellBook;
};
