#include "SpellBook.hpp"
#include "ASpell.hpp"


SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{
    _spellBook.clear();
}
void SpellBook::learnSpell(ASpell* spell)
{
    if (spell != nullptr) // OLVIDADO!!!
    {
        if (_spellBook.find(spell->getName()) == _spellBook.end())
            _spellBook[spell->getName()] = spell->clone(); 
    }
}

void SpellBook::forgetSpell(const string &spell)
{
    map<string, ASpell*>::iterator it;
    it = _spellBook.find(spell);
    if (it != _spellBook.end())
    {
        delete it->second;
        _spellBook.erase(spell);
    }
}

ASpell* SpellBook::createSpell(const string &spell_name)
{
    map<string, ASpell*>::iterator it;

    it = _spellBook.find(spell_name);
    if (it != _spellBook.end())
        return it->second->clone();
    return nullptr;
}