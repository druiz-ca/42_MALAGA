#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(const string& type)
{
	this->_type = type;
}

ATarget::~ATarget()
{}

const string& ATarget::getType() const
{
	return (this->_type);
}

void ATarget::getHitBySpell(const ASpell& spell) const
{
	cout << this->_type << " has been " << spell.getEffects() << "!" << endl;
}
