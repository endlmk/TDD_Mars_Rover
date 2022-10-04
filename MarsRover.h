#include <string>

class MarsRover
{
  int x_ = 0;
  int y_ = 0;
  char direction_ = 'N';
public:
  MarsRover(int x, int y, char direction);
  std::string CurrentState();
};
