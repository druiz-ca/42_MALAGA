#pragma once
#include <iostream>

using namespace std;

class ASpell;

class ATarget
{
	public:
		ATarget(const string& type);
		virtual ~ATarget();

		const string& getType() const;
		virtual ATarget* clone() const = 0;
		void getHitBySpell(const ASpell&) const;
	
	protected:
		string _type;
};
