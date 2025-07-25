#include "Warlock.hpp"
#include "ATarget.hpp"
#include "ASpell.hpp"

Warlock::Warlock(const string &name, const string&title)
{
    this->_name = name;
    this->_title = title;
    cout << this->_name << ": this lokks lije another... " << endl;
}

Warlock::~Warlock()
{
    cout << this->_name << "My job here is done" << endl;
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
    cout << this->_name << "I am" << this->_name << this->_title << endl;
}

void Warlock::learnSpell(ASpell* spell)
{
	_spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(const string spell)
{
	_spellBook.forgetSpell(spell);
}

void Warlock::launchSpell(const string spell, const ATarget& target)
{
	ASpell* spell_ptr = _spellBook.createSpell(spell);

	if (spell_ptr != nullptr)
	{
		spell_ptr->launch(target);
		delete spell_ptr;
	}
}