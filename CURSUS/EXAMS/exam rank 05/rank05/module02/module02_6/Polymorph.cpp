#include "Polymorph.hpp"

// x error en el nombre solo imprimia 1 linea!!!
Polymorph::Polymorph(): ASpell("Polymorph", "turned into a critter")
{}

Polymorph::~Polymorph()
{}

ASpell* Polymorph::clone() const
{
    return (new Polymorph);
}