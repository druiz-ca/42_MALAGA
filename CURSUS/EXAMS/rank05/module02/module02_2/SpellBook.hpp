#pragma once // NECESARIO

#include <iostream>
#include <map>

using namespace std;

class ASpell;

class SpellBook
{
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell* spell);
        void forgetSpell(const string& spell); // x la & petaba!!
        ASpell* createSpell(const string& spell);
    
    private:
        map<string, ASpell*> _spellBook;
};