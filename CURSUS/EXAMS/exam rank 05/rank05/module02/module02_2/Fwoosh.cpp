#include "Fwoosh.hpp"

Fwoosh::Fwoosh(): ASpell("Fwoosh", "fhwooshed")
{}

Fwoosh::~Fwoosh()
{}

ASpell* Fwoosh::clone() const
{
    return (new Fwoosh());
}