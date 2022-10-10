#include <gtest/gtest.h>
#include "MarsRover.h"

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
    rover.Move('f');
    EXPECT_STREQ("1 3 N", rover.CurrentState().c_str());
    rover.Move('b');
    EXPECT_STREQ("1 2 N", rover.CurrentState().c_str());
  }

  {
    MarsRover rover(1, 2, 'S');
    rover.Move('f');
    EXPECT_STREQ("1 1 S", rover.CurrentState().c_str());
    rover.Move('b');
    EXPECT_STREQ("1 2 S", rover.CurrentState().c_str());
  }

  {
    MarsRover rover(1, 2, 'E');
    rover.Move('f');
    EXPECT_STREQ("2 2 E", rover.CurrentState().c_str());
    rover.Move('b');
    EXPECT_STREQ("1 2 E", rover.CurrentState().c_str());
  }

  {
    MarsRover rover(1, 2, 'W');
    rover.Move('f');
    EXPECT_STREQ("0 2 W", rover.CurrentState().c_str());
    rover.Move('b');
    EXPECT_STREQ("1 2 W", rover.CurrentState().c_str());
  }
}

TEST(MarsRoverTest, CanTurnByCommand) {
  {
    MarsRover rover(1, 2, 'N');
    rover.Turn('l');
    EXPECT_STREQ("1 2 W", rover.CurrentState().c_str());
    rover.Turn('r');
    EXPECT_STREQ("1 2 N", rover.CurrentState().c_str());
  }
}