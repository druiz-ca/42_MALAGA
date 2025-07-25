#include "Fwoosh.hpp"

Fwoosh::Fwoosh(): ASpell("Fwoosh", "fwhoosed")
{}

Fwoosh::~Fwoosh()
{}

ASpell* Fwoosh::clone() const
{
    return (new Fwoosh);
}