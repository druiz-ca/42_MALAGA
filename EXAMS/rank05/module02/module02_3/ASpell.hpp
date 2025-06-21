#pragma once
#include <iostream>

using namespace std;

class ATarget;

class ASpell
{
    public:
        ASpell(const string& name, const string& effects);
        virtual ~ASpell();

        string getName() const;
        string getEffects() const;

        virtual ASpell* clone() const = 0;
        void launch(const ATarget&) const;

    protected:
        string _name;
        string _effects;
};  