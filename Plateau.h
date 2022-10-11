#pragma once

class Plateau {
  int right_;
  int top_;
public:  
  Plateau(int right, int top);
  void GetPosition(int x, int y, int& plateau_x, int& plateau_y);
};
