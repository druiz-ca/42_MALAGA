#pragma once
#include <iostream>
#include <map>

using namespace std;
class ASpell;
class ATarget;
class TargetGenerator
{
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget*);
		void forgetTargetType(const string&);
		ATarget* createTarget(const string&);

	private:
		map<string, ATarget*> _targetmap;
};
