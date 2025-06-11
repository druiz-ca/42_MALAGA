#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

class ASpell;
class ATarget;

class Warlock
{
    public:
        Warlock(const string& name, const string& title);
        ~Warlock();

        const string& getName() const;
        const string& getTitle() const;
        void setTitle(const string &title);
        // el settitle no puede llevar const porque va a modificar
        // el objeto!!!! añadiendo title!!!
        void introduce() const;

        void learnSpell(ASpell* spell);
        void forgetSpell(string spell);
        void launchSpell(string spell, ATarget& target);

    private:
        string _name;
        string _title;
        map<string, ASpell*> _spellBook;
};