#pragma once
#include <set>

class Plateau {
  int right_;
  int top_;
  std::set<std::pair<int, int>> obstacles_;
public:  
  Plateau(int right, int top);
  void GetPosition(int x, int y, int& plateau_x, int& plateau_y);
  void SetObstacle(int x, int y);
  bool IsExistObstacle(int x, int y) const;
};
