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

        void learnSpell(ASpell* spell);
        void forgetSpell(string const &spell);
        ASpell* createSpell(string const &spell);

    private:
        map<string, ASpell*> _spellBook;
};