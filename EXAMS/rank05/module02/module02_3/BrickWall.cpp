#include "BrickWall.hpp"

BrickWall::BrickWall(): ATarget("inconspicious Red -brick erall")
{}

BrickWall::~BrickWall()
{}

ATarget* BrickWall::clone() const
{
    return (new BrickWall);
}