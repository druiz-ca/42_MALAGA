#pragma once

#include <iostream>
#include <map>
#include "SpellBook.hpp" // no sirve con class Spellbook!!!

using namespace std;

class ASpell;
class ATarget;

class Warlock
{
    public:
        Warlock(const string &name, const string& title);
        ~Warlock();

        const string& getName() const;
        const string& getTitle() const;

        void setTitle(const string&);
        void introduce() const;

        void learnSpell(ASpell*);
        void forgetSpell(string);
        void launchSpell(string, const ATarget&);

    private:
        string _name;
        string _title;
        SpellBook spellBook;
};