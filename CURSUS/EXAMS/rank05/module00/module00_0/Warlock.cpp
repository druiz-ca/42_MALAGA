
#include "Warlock.hpp"

Warlock::Warlock(string const &name, string const &title)
{
    this->name = name;
    this->title = title;
    cout << this->name << ": What a boring day" << endl;
}

// si implementas el constructor pero no el destructor peta!!
Warlock::~Warlock()
{
    cout << this->name << ": My job is donde!" << endl;
}

void Warlock::introduce(void) const
{
    cout << this->name << ": My name is " << this->name << ", " << this->title << "!" << endl;
}

void Warlock::setTitle(string const &newTitle)
{
    this->title = newTitle;
}