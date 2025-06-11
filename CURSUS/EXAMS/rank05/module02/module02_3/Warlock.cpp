#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

Warlock::Warlock(const string& name, const string& title)
{
    this->_name = name;
    this->_title = title;
    cout << "This looks like another..." << endl;
}

Warlock::~Warlock()
{
    cout << this->_name << "my job here is done" << endl;
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
    cout << this->_name << ":" << this->_name << this->_title << "!" << endl;
}

void Warlock::learnSpell(ASpell* spell)
{
    spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(string spell)
{
    spellBook.forgetSpell(spell);
}
// me habia olvidado de Warlock:: !!!!!
// lo del puntero es solo en el Warlock!!! 
void Warlock::launchSpell(string spell, const ATarget& target)
{
    ASpell* spell_ptr = spellBook.createSpell(spell);
    if (spell_ptr != nullptr)
    {
        spell_ptr->launch(target);
        delete spell_ptr;
    }
}