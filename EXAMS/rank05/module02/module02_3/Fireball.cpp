#include "Fireball.hpp"

Fireball::Fireball(): ASpell("Fireabll", "burnt to a crisp")
{}

Fireball::~Fireball()
{}

ASpell* Fireball::clone() const
{
    return (new Fireball);
}