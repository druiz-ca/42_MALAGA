#pragma once
#include <iostream>

using namespace std;

class ASpell;

class ATarget
{
    public:
        ATarget(const string &type);
        virtual ~ATarget();

        const string& getType() const;
        virtual ATarget* clone() const = 0; // me olvidada el virtual y el 0
        void getHitBySpell(const ASpell& spell) const;

    protected:
        string _type;
};