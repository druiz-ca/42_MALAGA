#include "ASpell.hpp"
#include "ATarget.hpp"
// en el hpp no, pero en la implementacion si necesita el ATARget

ASpell::ASpell(const string& name, const string& effects)
{
    this->_name = name;
    this->_effects = effects;
}

ASpell::~ASpell()
{}

const string& ASpell::getName() const
{
    return(this->_name);
}

const string& ASpell::getEffects() const
{
    return (this->_effects);
}

void ASpell::launch(const ATarget& target) const // lleva const!!
{
    target.getHitBySpell(*this);
}