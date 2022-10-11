#pragma once
#include <string>
#include "Plateau.h"

class MarsRover
{
  int x_ = 0;
  int y_ = 0;
  char direction_ = 'N';
  Plateau plateau_;
public:
  MarsRover(int x, int y, char direction, Plateau plateau);
  std::string CurrentState();
  void ExecuteCommand(char command);
private:
  void Move(char f_or_b);
  void Turn(char l_or_r);
};
