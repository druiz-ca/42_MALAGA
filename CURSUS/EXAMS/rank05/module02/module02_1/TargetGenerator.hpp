#pragma once

#include <iostream>
#include <string>
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

    private: // esto no lo dice!!!
        map<string, ATarget*> _target_types;
};