#include "TargetGenerator.hpp"
#include "ATarget.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{}

void TargetGenerator::learnTargetType(ATarget* target)
{
    if (_Target_map.find(target->getType()) == _Target_map.end())
        _Target_map[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(string const & target)
{
    map<string, ATarget*>::iterator it = _Target_map.find(target);
    if (it != _Target_map.end())
        _Target_map.erase(target);
}

ATarget* TargetGenerator::createTarget(string const &target)
{
    map<string, ATarget*>::iterator it = _Target_map.find(target);
    if (it != _Target_map.end())
        return (it->second->clone());
    return (nullptr);
}