#pragma once
// #include "Warlock.hpp" NO PORQUE SE LIA!!!
#include <iostream>
#include <string>
#include <map>

using namespace std;

class ASpell;

class ATarget
{
    public:
        ATarget(const string& type);
        ~ATarget();

        const string& getType() const;
        virtual ATarget* clone() const = 0;
        void getHitBySpell(const ASpell& spell) const; // ek const!!
    protected:
        string _type;
};