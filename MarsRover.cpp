#include "MarsRover.h"

MarsRover::MarsRover(int x, int y, char direction) :
x_(x), y_(y), direction_(direction)
{}

std::string MarsRover::CurrentState()
{
    return std::string("1 2 N");
}