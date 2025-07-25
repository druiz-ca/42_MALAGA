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
		if (_targetmap.find(target->getType()) == _targetmap.end())
			_targetmap[target->getType()] = target;
	}
}

void TargetGenerator::forgetTargetType(const string& target)
{
	map<string, ATarget*>::iterator it = _targetmap.find(target);
	if (it != _targetmap.end())
		_targetmap.erase(target);
}

ATarget* TargetGenerator::createTarget(const string& target)
{
	map<string, ATarget*>::iterator it = _targetmap.find(target);
	if (it != _targetmap.end())
		return (it->second->clone());
	return nullptr;
}
