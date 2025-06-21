#pragma once
#include <iostream>
#include <map>

using namespace std;

class ASpell;

class SpellBook
{
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell*);
        void forgetSpell(string const &);
        ASpell* createSpell(string const &);
    
    private:
        map<string, ASpell*> _SpellBook;
};