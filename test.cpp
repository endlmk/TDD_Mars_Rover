#include <gtest/gtest.h>
#include "MarsRover.h"
#include "Plateau.h"

TEST(MarsRoverTest, CanOutputCurrentState) {
  {
    MarsRover rover(1, 2, 'N');
    EXPECT_STREQ("1 2 N", rover.CurrentState().c_str());
  }

  {
    MarsRover rover(5, 6, 'W');
    EXPECT_STREQ("5 6 W", rover.CurrentState().c_str());
  }
}

TEST(MarsRoverTest, CanMoveByCommand) {
  {
    MarsRover rover(1, 2, 'N');
    rover.ExecuteCommand('f');
    EXPECT_STREQ("1 3 N", rover.CurrentState().c_str());
    rover.ExecuteCommand('b');
    EXPECT_STREQ("1 2 N", rover.CurrentState().c_str());
  }

  {
    MarsRover rover(1, 2, 'S');
    rover.ExecuteCommand('f');
    EXPECT_STREQ("1 1 S", rover.CurrentState().c_str());
    rover.ExecuteCommand('b');
    EXPECT_STREQ("1 2 S", rover.CurrentState().c_str());
  }

  {
    MarsRover rover(1, 2, 'E');
    rover.ExecuteCommand('f');
    EXPECT_STREQ("2 2 E", rover.CurrentState().c_str());
    rover.ExecuteCommand('b');
    EXPECT_STREQ("1 2 E", rover.CurrentState().c_str());
  }

  {
    MarsRover rover(1, 2, 'W');
    rover.ExecuteCommand('f');
    EXPECT_STREQ("0 2 W", rover.CurrentState().c_str());
    rover.ExecuteCommand('b');
    EXPECT_STREQ("1 2 W", rover.CurrentState().c_str());
  }
}

TEST(MarsRoverTest, CanTurnByCommand) {
  {
    MarsRover rover(1, 2, 'N');
    rover.ExecuteCommand('l');
    EXPECT_STREQ("1 2 W", rover.CurrentState().c_str());
    rover.ExecuteCommand('r');
    EXPECT_STREQ("1 2 N", rover.CurrentState().c_str());
  }
  {
    MarsRover rover(1, 2, 'S');
    rover.ExecuteCommand('l');
    EXPECT_STREQ("1 2 E", rover.CurrentState().c_str());
    rover.ExecuteCommand('r');
    EXPECT_STREQ("1 2 S", rover.CurrentState().c_str());
  }
  {
    MarsRover rover(1, 2, 'W');
    rover.ExecuteCommand('l');
    EXPECT_STREQ("1 2 S", rover.CurrentState().c_str());
    rover.ExecuteCommand('r');
    EXPECT_STREQ("1 2 W", rover.CurrentState().c_str());
  }
  {
    MarsRover rover(1, 2, 'E');
    rover.ExecuteCommand('l');
    EXPECT_STREQ("1 2 N", rover.CurrentState().c_str());
    rover.ExecuteCommand('r');
    EXPECT_STREQ("1 2 E", rover.CurrentState().c_str());
  }
}

TEST(PlateauTest, CanGetPlateauPosition) {
  Plateau plateau(5, 5);
  int pos_x = 0;
  int pos_y = 0;
  plateau.GetPosition(2, 3, pos_x, pos_y);
  EXPECT_EQ(2, pos_x);
  EXPECT_EQ(3, pos_y);
  plateau.GetPosition(6, 3, pos_x, pos_y);
  EXPECT_EQ(0, pos_x);
  EXPECT_EQ(3, pos_y);
  plateau.GetPosition(4, 6, pos_x, pos_y);
  EXPECT_EQ(4, pos_x);
  EXPECT_EQ(0, pos_y);
}
