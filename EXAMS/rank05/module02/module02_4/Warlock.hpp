#pragma once

#include <iostream>
#include <map>
#include "SpellBook.hpp"

using namespace std;

class ATarget;
class ASpell;

class Warlock
{  
    public:
        Warlock(const string &name, const string&title);
        ~Warlock();

        const string& getName() const;
        const string& getTitle() const;

        void setTitle(const string& title);
        void introduce() const;  

        void learnSpell(ASpell* spell);
        void forgetSpell(const string spell);
        void launchSpell(const string spell, const ATarget& target); // el const no lo pide
    
    private:
        string _name;
        string _title;
        SpellBook _spellBook;
};