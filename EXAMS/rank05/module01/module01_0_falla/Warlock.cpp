
#include "Warlock.hpp"

Warlock::Warlock(string const &name, string const &title)
{
    this->_name = name;
    this->_title = title;
    cout << this->_name << ": This looks like another boring day." << endl;
}

// si implementas el constructor pero no el destructor peta!!
Warlock::~Warlock()
{
    cout << this->_name << ": My job is donde!" << endl;
}

void Warlock::introduce(void) const
{
    cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << endl;
}

void Warlock::setTitle(string const &newTitle)
{
    this->_title = newTitle;
}

void Warlock::learnSpell(ASpell *spell)
{
    if (spell != nullptr)
    {
        if (_spellBook.find(spell->getName()) == _spellBook.end())
            _spellBook[spell->getName()] = spell->clone();
    }
}

void Warlock::forgetSpell(string spell)
{
    map<string, ASpell*>::iterator it;

    if (_spellBook.find(spell) != _spellBook.end())
    {
        delete it->second;
        _spellBook.erase(spell);
    }
}

void Warlock::launchSpell(string spell, const ATarget &target)
{
    map<string, ASpell*>::iterator it;

    if (_spellBook.find(spell) != _spellBook.end())
        it->second->launch(target);
} 