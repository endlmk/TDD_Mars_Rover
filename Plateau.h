#pragma once

class Plateau {
  int top_;
  int right_;
public:  
  Plateau(int top, int right);
  void GetPosition(int x, int y, int& plateau_x, int& plateau_y);
};
