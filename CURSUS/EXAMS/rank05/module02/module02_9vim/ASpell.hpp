#pragma once
#include <iostream>

using namespace std;

class ATarget;

class ASpell
{
	public:
		ASpell(const string& name, const string& title);
		virtual ~ASpell();

		const string& getName() const;
		const string& getEffects() const;
		virtual ASpell* clone() const = 0;
		void launch(const ATarget&) const;
	protected:
		string _name;
		string _effects;
};
