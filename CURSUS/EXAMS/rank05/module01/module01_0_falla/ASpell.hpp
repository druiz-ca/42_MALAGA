
#ifndef ASPELL_HPP
# define ASPELL_HPP

#include "Warlock.hpp"

using namespace std;

// crea una clase para los objetivos
class ATarget;

// crea una clase para los hechizos
class ASpell
{
    public:
        ASpell(string const &name, string const &effects);
        virtual ~ASpell();

        string getName() const;
        string getEffects() const;
        void launch(const ATarget &Spell) const;
        // devuelve una copia del hechizo(spell)
            // virtual pura para que cada objeto la modifique
        virtual ASpell* clone() const = 0;

    protected:
        string name;
        string effects;

};


#endif