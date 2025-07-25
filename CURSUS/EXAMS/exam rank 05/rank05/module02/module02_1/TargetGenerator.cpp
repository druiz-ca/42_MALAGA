#include "TargetGenerator.hpp"
#include "ATarget.hpp" // no olvidarse en el .cpp!!!

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{
    _target_types.clear();
}

void TargetGenerator::learnTargetType(ATarget* target)
{
    if (target != nullptr)
    {
        if (_target_types.find(target->getType()) == _target_types.end())
            _target_types[target->getType()] = target; // no clone!!!
    }
}

void TargetGenerator::forgetTargetType(const string& target)
{
    map<string, ATarget*>::iterator it;
    it = _target_types.find(target);

    if (it != _target_types.end())
        _target_types.erase(target);
        // AQUI NO VA DELETE!!!????
}

ATarget* TargetGenerator::createTarget(const string& target_name)
{
    map<string, ATarget*>::iterator it;
    it = _target_types.find(target_name);
    if (it != _target_types.end())
        return it->second->clone(); // aqui si clone!!!
    return nullptr;
}