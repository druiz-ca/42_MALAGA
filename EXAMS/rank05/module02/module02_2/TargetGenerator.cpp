#include "TargetGenerator.hpp"
#include "ATarget.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{
    _target_generator.clear(); // NO SE OLVIDE!!!
}

void TargetGenerator::learnTargetType(ATarget* target)
{
    if (target != nullptr) // OLVIDADO!!
    {
        if (_target_generator.find(target->getType()) == _target_generator.end())
            _target_generator[target->getType()] = target; // NO CLONE!!
    }
}

void TargetGenerator::forgetTargetType(const string& target)
{
    map<string, ATarget*>::iterator it;

    it = _target_generator.find(target);
    if (it != _target_generator.end())
        _target_generator.erase(target);
        // SIN DELETE PQ NO SE HA HECHO NEW!!!
}
// crear una copia!!!! de un target existente!!!!
ATarget* TargetGenerator::createTarget(const string& target)
{
    map<string, ATarget*>::iterator it;

    it = _target_generator.find(target);
    if (it != _target_generator.end())
        return it->second->clone();
    return nullptr;
}