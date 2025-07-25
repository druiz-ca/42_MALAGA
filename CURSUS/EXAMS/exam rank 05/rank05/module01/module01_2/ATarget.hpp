#pragma once

#include "Warlock.hpp"

using namespace std;

class ASpell;

class ATarget
{
    public:
        ATarget(const string& type);
        virtual ~ATarget();

        const string& getType() const;
        virtual ATarget* clone() const = 0;
        void getHitBySpell(const ASpell& spell) const;
                                // sin el ultimo const peta!!!
                        // sin el 1er const peta!!!
    protected:
        string _type;
};