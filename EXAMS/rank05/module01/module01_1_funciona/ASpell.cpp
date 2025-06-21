
#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(string const &name, string const &effects)
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

void ASpell::launch(const ATarget &target) const
{
    target.getHitBySpell(*this);
}
