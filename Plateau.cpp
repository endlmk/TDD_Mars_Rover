#include "Plateau.h"

Plateau::Plateau(int right, int top)
: right_(right), top_(top)
{}

void Plateau::GetPosition(int x, int y, int& plateau_x, int& plateau_y)
{
  if(x > right_)
  {
    plateau_x = 0;
  }
  else if(x < 0)
  {
    plateau_x = right_;
  }
  else
  {
    plateau_x = x;
  }
  
  if(y > top_)
  {
    plateau_y = 0;
  }
  else if(y < 0)
  {
    plateau_y = top_;
  }
  else
  {
    plateau_y = y;
  }
}