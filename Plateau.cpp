#include "Plateau.h"

Plateau::Plateau(int right, int top)
: right_(right), top_(top)
{}

int WrapAtEdge(int lower, int upper, int value)
{
  if(value > upper)
  {
    return lower;
  }
  else if(value < lower)
  {
    return upper;
  }
  else
  {
    return value;
  }
}

void Plateau::GetPosition(int x, int y, int& plateau_x, int& plateau_y)
{
  plateau_x = WrapAtEdge(0, right_, x);
  plateau_y = WrapAtEdge(0, top_, y);
}

void Plateau::SetObstacle(int x, int y)
{
  obstacles_.insert({x, y});
}

bool Plateau::IsExistObstacle(int x, int y) const
{
  return obstacles_.find({x, y}) != obstacles_.end();
}
