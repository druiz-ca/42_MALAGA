#pragma once

#include <iostream>
#include <map>

using namespace std;

class ATarget;

class TargetGenerator
{
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget*);
        void forgetTargetType(string const &);
        ATarget* createTarget(string const &);

    private:
        map<string, ATarget*> _target_map;
};