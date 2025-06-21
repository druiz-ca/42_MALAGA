#include "TargetGenerator.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{}

void TargetGenerator::learnTargetType(ATarget* target)
{
	if (target != nullptr)
	{
		if (_target_map.find(target->getType()) == _target_map.end())
			_target_map[target->getType()] = target;
	}
}

void TargetGenerator::forgetTargetType(const string& target)
{
	map<string, ATarget*>::iterator it = _target_map.find(target);
	if (it != _target_map.end())
		_target_map.erase(target);
}

ATarget* TargetGenerator::createTarget(const string& target)
{
	map<string, ATarget*>::iterator it = _target_map.find(target);
	if (it != _target_map.end())
		return (it->second->clone());
	return nullptr;
}
