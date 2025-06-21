#pragma once
#include <iostream>
#include <map>

using namespace std;

class ASpell;

class SpellBook
{
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell*);
		void forgetSpell(const string& spell);
		ASpell* createSpell(const string&);
	private:
		map<string, ASpell*> _spellBook;
};
