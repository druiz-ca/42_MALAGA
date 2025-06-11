#include "BrickWall.hpp"

// por poner el nombre mal!!! daba seg fault xq no lo encontraba!!!
BrickWall::BrickWall(): ATarget("Inconspicuous Red-brick Wall")
{}

BrickWall::~BrickWall()
{}

ATarget* BrickWall::clone() const
{
    return (new BrickWall);
}