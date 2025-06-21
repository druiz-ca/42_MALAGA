
#include "ATarget.hpp"

ATarget::ATarget(const string &type)
{
    this->type = type;
}

ATarget::~ATarget()
{}

const string& ATarget::getType() const
{
    return (this->type);
}

void ATarget::getHitBySpell(const ASpell &src) const
{
    cout << "!" << this->getType() << " has been " << src.getEffects() << "!" << endl;
}