

#ifndef ATARGET_HPP
# define ATARGET_HPP

#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

using namespace std;

class ASpell;

class ATarget
{
    public:
        ATarget(string const &type);
        virtual ~ATarget();

        const string &getType() const;
        void getHitBySpell(ASpell const &spell) const;
        // al tener un método virtual puro convierte la clase
        // ATarget en una clase abstracta
        virtual ATarget* clone() const = 0;

    protected:
        string type;
};


#endif

/* Las clases abstractas (método virtual puro) están diseñadas
pera ser clases bases y que otras clases derivadas hereden
la estructura de ellas y entonces implementen los métodos
virtuales
*/