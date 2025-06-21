#pragma once
#include <iostream>

using namespace std;

class Warlock
{
	public:
		Warlock(const string& name, const string& title);
		~Warlock();

		const string& getName() const;
		const string& getTitle() const;
		void setTitle(const string& title);
		void introduce() const;

	private:
		string _name;
		string _title;
};
