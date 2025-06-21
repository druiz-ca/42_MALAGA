 

#include "ASpell.hpp"

ASpell::ASpell(const string &name, const string &effects)
{
    this->name = name;
    this->effects = effects;
}

ASpell::~ASpell()
{}

string ASpell::getName() const
{
    return (this->name);
}

string ASpell::getEffects() const
{
    return (this->effects);
}

void ASpell::launch(const ATarget &src) const
{
    src.getHitBySpell(*this);
}