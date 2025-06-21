#include "BrickWall.hpp"

BrickWall::BrickWall(): ATarget("Inconspicuous Red-brick wall")
{}

BrickWall::~BrickWall()
{}

ATarget *BrickWall::clone() const
{
    return (new BrickWall()); // LOS PARENTESIS!!!!
}