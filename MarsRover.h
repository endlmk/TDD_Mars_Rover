#pragma once
#include <string>

class MarsRover
{
  int x_ = 0;
  int y_ = 0;
  char direction_ = 'N';
public:
  MarsRover(int x, int y, char direction);
  std::string CurrentState();
  void ExecuteCommand(char command);
private:
  void Move(char f_or_b);
  void Turn(char l_or_r);
};
