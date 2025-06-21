#include "TargetGenerator.hpp"
#include "ATarget.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{}

void TargetGenerator::learnTargetType(ATarget* target)
{
    if (target != nullptr)
    {
        if (Target_map.find(target->getType()) == Target_map.end())
            Target_map[target->getType()] = target;
    }
}

void TargetGenerator::forgetTargetType(const string& target)
{
    map<string, ATarget*>::iterator it;
    it = Target_map.find(target);
    if (it != Target_map.end())
        //delete it->second; NO LLEVA DELETE PQ NO HA HECHO CLONE!! ES SOL UNA REFERENCIA
        Target_map.erase(target);
}
// mas bien copyTarget!!!
ATarget* TargetGenerator::createTarget(const string &target)
{
    map<string, ATarget*>::iterator it;
    it = Target_map.find(target);
    if (it != Target_map.end())
        return (it->second->clone()); // clone xq esta creando targets(dummy, etc)
    return nullptr; // se me olvidaba esto
}