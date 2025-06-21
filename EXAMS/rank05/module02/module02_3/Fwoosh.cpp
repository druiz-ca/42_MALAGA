#include "Fwoosh.hpp"

Fwoosh::Fwoosh():ASpell("Fwoosh", "fwoshed")
{}

Fwoosh::~Fwoosh()
{}

ASpell* Fwoosh::clone() const
{
    return (new Fwoosh);
}
