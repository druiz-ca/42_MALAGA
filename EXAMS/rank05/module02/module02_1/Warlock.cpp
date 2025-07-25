#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

Warlock::Warlock(const string& name, const string &title)
{
    this->_name = name;
    this->_title = title;
    cout << this->_name << ": This looks like another boring day." << endl;
}

Warlock::~Warlock()
{
    cout << this->_name << ": My job here is done!" << endl;
}

const string& Warlock::getName() const
{
    return (this->_name);
}

const string& Warlock::getTitle() const
{
    return(this->_title);
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
    _spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(string spell)
{
    _spellBook.forgetSpell(spell);
}

void Warlock::launchSpell(string spell_name, ATarget& target)
{
    ASpell* ptr_spell = _spellBook.createSpell(spell_name);
    if (ptr_spell != nullptr)
    {
        ptr_spell->launch(target);
        delete ptr_spell;
    }
}