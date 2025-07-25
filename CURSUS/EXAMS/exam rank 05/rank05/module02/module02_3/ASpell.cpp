#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(const string& name, const string& effects)
{
    this->_name = name;
    this->_effects = effects;
}

ASpell::~ASpell()
{}

string ASpell::getName() const
{
    return (this->_name);
}

string ASpell::getEffects() const
{
    return (this->_effects);
}

// como el parametro es una referencia constante al objeto
// solo puedo usar metodos de ATarget que esten marcados
// como const!!! (getHitByspell)
void ASpell::launch(const ATarget& target) const
{
    target.getHitBySpell(*this);
}