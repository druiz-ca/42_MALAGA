#include "Polymorph.hpp"

Polymorph::Polymorph(): ASpell("polymorph", "burnt to a crisp")
{}

Polymorph::~Polymorph()
{}

ASpell* Polymorph::clone() const
{
    return (new Polymorph()); // PARENTESIS!!!
}