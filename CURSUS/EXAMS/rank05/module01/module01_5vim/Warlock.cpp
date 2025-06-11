#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

Warlock::Warlock(const string& name, const string& title)
{
	this->_name = name;
	this->_title = title;
	cout << this->_name << ": This looks like another boring day." << endl;	
}

Warlock::~Warlock()
{
	cout << this->_name << ": My job here is done!"<< endl;
}

const string& Warlock::getName() const
{
	return (this->_name);
}

const string& Warlock::getTitle() const
{
	return (this->_title);
}

void Warlock::setTitle(const string& title)
{
	this->_title = title;
}

void Warlock::introduce() const
{
	cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << endl;
}

void Warlock::learnSpell(ASpell* spell)
{
	if (spell != nullptr)
	{
		if (_spellBook.find(spell->getEffects()) == _spellBook.end())
			_spellBook[spell->getName()] = spell;
	}
}

void Warlock::forgetSpell(string spell)
{
	map<string, ASpell*>::iterator it = _spellBook.find(spell);
	if (it != _spellBook.end())
	{
		_spellBook.erase(spell);
		delete it->second;
	}
}

void Warlock::launchSpell(string spell, ATarget& target)
{
	map<string, ASpell*>::iterator it = _spellBook.find(spell);
	if (it != _spellBook.end())
		it->second->launch(target);
}
