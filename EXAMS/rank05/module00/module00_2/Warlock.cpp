
#include "Warlock.hpp"

Warlock::Warlock(string const &name, string const &title)
{
    this->name = name;
    this->title = title;
    cout << this->name << ": What a boring dat" << endl;
}

Warlock::~Warlock()
{
    cout << this->name << ": My job is done!" << endl;
}

void Warlock::setTitle(string const &title)
{
    this->title = title;
}

void Warlock::introduce()
{
    cout << this->name << ": My name is " << this->name << ", " << this->title << "!" << endl;
}