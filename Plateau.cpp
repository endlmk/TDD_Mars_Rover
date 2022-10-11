#include "Plateau.h"

Plateau::Plateau(int top, int right)
: top_(top), right_(right)
{}

void Plateau::GetPosition(int x, int y, int& plateau_x, int& plateau_y)
{
  plateau_x = (x > right_) ? 0 : x;
  plateau_y = (y > top_) ? 0 : y;
}