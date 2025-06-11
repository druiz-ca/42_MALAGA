 
#include <iostream>

using namespace std;

class ATarget;

class ASpell
{
    public:
        ASpell(string const &name, string const &effects);
        virtual ~ASpell(); // si es abstracta, el destructor también virtual!

        string getName() const;
        string getEffects() const;
        virtual ASpell* clone() const = 0;
        void launch(const ATarget &target) const;

    protected:
        string _name;
        string _effects;
};