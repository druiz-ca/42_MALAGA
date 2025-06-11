#include "Polymorph.hpp"

Polymorph::Polymorph(): ASpell("Polymorh", "turned iunto a critter")
{}

Polymorph::~Polymorph()
{}

ASpell* Polymorph::clone() const
{
    return (new Polymorph);
}