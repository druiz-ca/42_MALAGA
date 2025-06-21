#include "TargetGenerator.hpp"
#include "ATarget.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{}

void TargetGenerator::learnTargetType(ATarget* target)
{
    if (_target_map.find(target->getType()) == _target_map.end())
        _target_map[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(string const &target)
{
    map<string, ATarget*>::iterator it = _target_map.find(target);
    if (it != _target_map.end())
        _target_map.erase(target);
}

ATarget* TargetGenerator::createTarget(string const &target)
{
    map<string, ATarget*>::iterator it = _target_map.find(target);
    if (it != _target_map.end())
        return (it->second->clone());
    return nullptr;
}