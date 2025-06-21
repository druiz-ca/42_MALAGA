#include <iostream>
#include <map>

using namespace std;

class ATarget;

class TargetGenerator
{
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget* target);
        void forgetTargetType(const string& target);
        ATarget* createTarget(const string& target);
    
    private:
        map<string, ATarget*> _target_generator;
};