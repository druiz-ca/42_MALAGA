#include "SpellBook.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{}

void SpellBook::learnSpell(ASpell* spell)
{
    if (spell != nullptr)
    {
        if (_SpellBook.find(spell->getName()) == _SpellBook.end())
            _SpellBook[spell->getName()] = spell;
    }
}

void SpellBook::forgetSpell(const string &spell)
{
    map<string, ASpell*>::iterator it;
    it = _SpellBook.find(spell);
    if (it != _SpellBook.end())
    {
        delete it->second;
        _SpellBook.erase(spell);
    }
}

ASpell* SpellBook::createSpell(const string& spell)
{
    map<string, ASpell*>::iterator it;
    it = _SpellBook.find(spell);
    if (it != _SpellBook.end()) // POR PONER == SEGMENTATION FAULT!!!!!!!!
        return (it->second->clone());
    return nullptr;
}