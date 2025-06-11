#pragma once //solo hay que ponerlo aqui!!!

#include <iostream>
#include <string>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"

using namespace std;

class Warlock
{
    public:
        Warlock(const string& name, const string &title);
        ~Warlock();

        const string& getName() const;
        const string& getTitle() const;

        void setTitle(const string &title);
        void introduce() const;

        void learnSpell(ASpell* spell);
        void forgetSpell(string spell);
        void launchSpell(string spell, ATarget& target);

    private:
        string _name;
        string _title;
        map<string, ASpell*> _spellBook;
};