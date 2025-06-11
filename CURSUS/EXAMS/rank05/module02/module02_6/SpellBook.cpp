#include "SpellBook.hpp"
#include "ASpell.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{}

void SpellBook::learnSpell(ASpell* spell)
{
    if (spell != nullptr)
    {
        if (_spellBook.find(spell->getName()) == _spellBook.end())
            _spellBook[spell->getName()] = spell;
    }
}

void SpellBook::forgetSpell(string const &spell)
{
    map<string, ASpell*>::iterator it = _spellBook.find(spell);
    if (it != _spellBook.end())
        _spellBook.erase(spell);
}

ASpell* SpellBook::createSpell(string const &spell)
{
    map<string, ASpell*>::iterator it = _spellBook.find(spell);
    if (it != _spellBook.end())
        return (it->second->clone());
    return nullptr;
}