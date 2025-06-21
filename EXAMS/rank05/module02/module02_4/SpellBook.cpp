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
        if (_SpellBook.find(spell->getName()) == _SpellBook.end())
            _SpellBook[spell->getName()] = spell->clone(); // no habia puesto clone!!!
    }
}

void SpellBook::forgetSpell(const string& spell)
{
    map<string, ASpell*>::iterator it = _SpellBook.find(spell);
    if (it != _SpellBook.end())
    {
        delete it->second;
        _SpellBook.erase(spell);
    }
}
/* devuelve una copia del hechizo que recibe x parametro 
Como el iterador ya apunta a ese hechizo con ese nombre
el return devuelve la copia de ese hechizo encontrado 
(no es que crée un hechizo nuevo!!!) */
ASpell* SpellBook::createSpell(const string& spell)
{
    map<string, ASpell*>::iterator it = _SpellBook.find(spell);
    if (it != _SpellBook.end())
        return (it->second->clone());
    return nullptr;
}