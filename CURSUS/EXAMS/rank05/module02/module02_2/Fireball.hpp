#include "ASpell.hpp"

class Fireball: public ASpell
{
    public: // OLVIDADO!!!
        Fireball();
        ~Fireball();

        ASpell* clone() const;
};