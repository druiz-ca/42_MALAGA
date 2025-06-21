#pragma once

#include "Warlock.hpp"

using namespace std;

class ATarget;

class ASpell
{
    public:
        ASpell(const string& name, const string& effects);
        virtual ~ASpell();

        const string& getName() const;
        const string& getEffects() const;

        void launch(const ATarget& target) const;
        virtual ASpell* clone() const = 0;
    protected:
        string _name;
        string _effects;
};