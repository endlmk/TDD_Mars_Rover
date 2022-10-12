#include "MarsRover.h"

MarsRover::MarsRover(int x, int y, char direction, Plateau plateau) :
x_(x), y_(y), direction_(direction), plateau_(plateau)
{}

std::string MarsRover::CurrentState()
{
  auto state = std::string(std::to_string(x_) + " " +
              std::to_string(y_) + " " +
              direction_);
  if(foundObstacle_)
  {
    state += " :Obstacle found, aborted.";
  }
  return state;
}

void MarsRover::ExecuteCommand(char command)
{
  if(foundObstacle_)
  {
    foundObstacle_ = false;
  }
  
  switch(command)
  {
    case 'f':
    case 'b':
      Move(command);
      break;
    case 'l':
    case 'r':
      Turn(command);
      break;
    default:
      break;
  }
}

void MarsRover::SendSequentialCommand(const std::string& commands)
{
  for(const auto& c : commands)
  {
    ExecuteCommand(c);
    if(foundObstacle_)
    {
      break;
    }
  }
}

void MarsRover::Move(char f_or_b)
{
  int move_to_coordinate = 0;
  switch(f_or_b)
  {
    case 'f':
      move_to_coordinate = 1;
      break;
    case 'b':
      move_to_coordinate = -1;
      break;
    default:
      break;
  }

  int prev_x = x_;
  int prev_y = y_;
  switch(direction_)
  {
    case 'N':
      y_ += move_to_coordinate;
      break;
    case 'S':
      y_ -= move_to_coordinate;
      break;
    case 'E':
      x_ += move_to_coordinate;
      break;
    case 'W':
      x_ -= move_to_coordinate;
      break;
    default:
      break;
  }

  plateau_.GetPosition(x_, y_, x_, y_);
  if(plateau_.IsExistObstacle(x_, y_))
  {
    foundObstacle_ = true;
    x_ = prev_x;
    y_ = prev_y;
  }
}

void MarsRover::Turn(char l_or_r)
{
  std::string directions = "NWSE";
  const auto index = directions.find(direction_);
  switch(l_or_r)
  {
    case 'l':
      direction_ = directions[(index + 1) % 4];
      break;
    case 'r':
      direction_ = directions[(index - 1 + 4) % 4];
      break;
    default:
      break;
  }
}
