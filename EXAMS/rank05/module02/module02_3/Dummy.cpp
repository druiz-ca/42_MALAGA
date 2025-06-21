#include "Dummy.hpp"

Dummy::Dummy():ATarget("taret practice dummy")
{}

Dummy::~Dummy()
{}

ATarget* Dummy::clone() const
{
    return (new Dummy);
}