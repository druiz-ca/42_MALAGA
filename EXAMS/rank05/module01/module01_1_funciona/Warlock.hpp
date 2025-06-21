
#include <iostream>
#include <map>

using namespace std;

class ASpell;
class ATarget;

class Warlock
{
    public:
        Warlock(const string &name, const string &title);
        ~Warlock();

        const string getName() const;
        const string getTitle() const;

        void setTitle(const string &title);
        void introduce() const;

        void learnSpell(ASpell* spell_obj);
        void forgetSpell(string spell);
        void launchSpell(string spell, const ATarget &target);

    private:
        string _name;
        string _title;
        map<string, ASpell*> _spellBook;

};