
#include <iostream>

class ASpell;

using namespace std;

class ATarget
{
    public:
        ATarget(const string &type);
        virtual ~ATarget();

        const string& getType() const;
        virtual ATarget* clone() const = 0;
        void getHitBySpell(const ASpell &spell) const;


    protected:
        string _type;
};