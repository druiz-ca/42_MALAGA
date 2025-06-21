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

        void learnTargetType(ATarget* target);
        void forgetTargetType(string const &target);
        ATarget* createTarget(string const &target);
        
    private:
        map<string, ATarget*> _target_map;
};