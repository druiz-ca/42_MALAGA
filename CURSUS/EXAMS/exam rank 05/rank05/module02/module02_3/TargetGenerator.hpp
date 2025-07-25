#include <iostream>
#include <map>

#pragma once

class ATarget;
using namespace std;

class TargetGenerator
{
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget*);
        void forgetTargetType(const string&);
        ATarget* createTarget(const string&);

    private:
        map<string, ATarget*> Target_map;
};