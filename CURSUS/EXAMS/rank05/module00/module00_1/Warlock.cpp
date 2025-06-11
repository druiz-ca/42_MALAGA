
#include "Warlock.hpp"

Warlock::Warlock(string const &name, string const &title)
{
    this->name = name;
    this->title = title;
    cout << this->name << ": What a boring day." << endl;
}

Warlock::~Warlock()
{
    cout << this->name << ": My job is donne!" << endl;
}

void Warlock::setTitle(string const &name)
{
    this->title = name;
}

void Warlock::introduce() const
{
    cout << this->name << ": My name is " << this->name << ", " << this->title << "!" << endl;
}