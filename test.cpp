#include <gtest/gtest.h>
#include "MarsRover.h"
#include "Plateau.h"

TEST(MarsRoverTest, CanOutputCurrentState) {
  {
    MarsRover rover(1, 2, 'N', Plateau(5, 5));
    EXPECT_STREQ("1 2 N", rover.CurrentState().c_str());
  }

  {
    MarsRover rover(5, 6, 'W', Plateau(5, 5));
    EXPECT_STREQ("5 6 W", rover.CurrentState().c_str());
  }
}

TEST(MarsRoverTest, CanMoveByCommand) {
  {
    MarsRover rover(1, 2, 'N', Plateau(5, 5));
    rover.ExecuteCommand('f');
    EXPECT_STREQ("1 3 N", rover.CurrentState().c_str());
    rover.ExecuteCommand('b');
    EXPECT_STREQ("1 2 N", rover.CurrentState().c_str());
  }

  {
    MarsRover rover(1, 2, 'S', Plateau(5, 5));
    rover.ExecuteCommand('f');
    EXPECT_STREQ("1 1 S", rover.CurrentState().c_str());
    rover.ExecuteCommand('b');
    EXPECT_STREQ("1 2 S", rover.CurrentState().c_str());
  }

  {
    MarsRover rover(1, 2, 'E', Plateau(5, 5));
    rover.ExecuteCommand('f');
    EXPECT_STREQ("2 2 E", rover.CurrentState().c_str());
    rover.ExecuteCommand('b');
    EXPECT_STREQ("1 2 E", rover.CurrentState().c_str());
  }

  {
    MarsRover rover(1, 2, 'W', Plateau(5, 5));
    rover.ExecuteCommand('f');
    EXPECT_STREQ("0 2 W", rover.CurrentState().c_str());
    rover.ExecuteCommand('b');
    EXPECT_STREQ("1 2 W", rover.CurrentState().c_str());
  }
}

TEST(MarsRoverTest, CanTurnByCommand) {
  {
    MarsRover rover(1, 2, 'N', Plateau(5, 5));
    rover.ExecuteCommand('l');
    EXPECT_STREQ("1 2 W", rover.CurrentState().c_str());
    rover.ExecuteCommand('r');
    EXPECT_STREQ("1 2 N", rover.CurrentState().c_str());
  }
  {
    MarsRover rover(1, 2, 'S', Plateau(5, 5));
    rover.ExecuteCommand('l');
    EXPECT_STREQ("1 2 E", rover.CurrentState().c_str());
    rover.ExecuteCommand('r');
    EXPECT_STREQ("1 2 S", rover.CurrentState().c_str());
  }
  {
    MarsRover rover(1, 2, 'W', Plateau(5, 5));
    rover.ExecuteCommand('l');
    EXPECT_STREQ("1 2 S", rover.CurrentState().c_str());
    rover.ExecuteCommand('r');
    EXPECT_STREQ("1 2 W", rover.CurrentState().c_str());
  }
  {
    MarsRover rover(1, 2, 'E', Plateau(5, 5));
    rover.ExecuteCommand('l');
    EXPECT_STREQ("1 2 N", rover.CurrentState().c_str());
    rover.ExecuteCommand('r');
    EXPECT_STREQ("1 2 E", rover.CurrentState().c_str());
  }
}

TEST(MarsRoverTest, MoveTowardEdge) {
  {
    MarsRover rover(2, 5, 'N', Plateau(5, 5));
    rover.ExecuteCommand('f');
    EXPECT_STREQ("2 0 N", rover.CurrentState().c_str());
  }
  {
    MarsRover rover(4, 0, 'S', Plateau(5, 5));
    rover.ExecuteCommand('f');
    EXPECT_STREQ("4 5 S", rover.CurrentState().c_str());
  }
  {
    MarsRover rover(0, 0, 'E', Plateau(5, 5));
    rover.ExecuteCommand('b');
    EXPECT_STREQ("5 0 E", rover.CurrentState().c_str());
  }
  {
    MarsRover rover(5, 3, 'W', Plateau(5, 5));
    rover.ExecuteCommand('b');
    EXPECT_STREQ("0 3 W", rover.CurrentState().c_str());
  }
}

TEST(MarsRoverTest, CanSendSequentialCommand) {
  {
    MarsRover rover(5, 3, 'N', Plateau(5, 5));
    rover.SendSequentialCommand("fff");
    EXPECT_STREQ("5 0 N", rover.CurrentState().c_str());
  }
  {
    MarsRover rover(5, 3, 'N', Plateau(5, 5));
    rover.SendSequentialCommand("fffbbb");
    EXPECT_STREQ("5 3 N", rover.CurrentState().c_str());
  }
  {
    MarsRover rover(1, 2, 'N', Plateau(5, 5));
    rover.SendSequentialCommand("lflflflff");
    EXPECT_STREQ("1 3 N", rover.CurrentState().c_str());
  }
  {
    MarsRover rover(3, 3, 'E', Plateau(5, 5));
    rover.SendSequentialCommand("ffrffrfrrf");
    EXPECT_STREQ("5 1 E", rover.CurrentState().c_str());
  }
}

TEST(MarsRoverTest, CanReportObstacles) {
  {
    auto plateau = Plateau(5, 5);
    plateau.SetObstacle(0, 1);
    MarsRover rover(0, 0, 'N', plateau);
    rover.ExecuteCommand('f');
    EXPECT_STREQ("0 0 N :Obstacle found, aborted.", rover.CurrentState().c_str());
    rover.ExecuteCommand('b');
    EXPECT_STREQ("0 5 N", rover.CurrentState().c_str());
    rover.ExecuteCommand('f');
    EXPECT_STREQ("0 0 N", rover.CurrentState().c_str());
    rover.ExecuteCommand('r');
    EXPECT_STREQ("0 0 E", rover.CurrentState().c_str());
    rover.ExecuteCommand('l');
    EXPECT_STREQ("0 0 N", rover.CurrentState().c_str());
  }

  {
    auto plateau = Plateau(5, 5);
    plateau.SetObstacle(0, 1);
    MarsRover rover(0, 0, 'N', plateau);
    rover.SendSequentialCommand("rflflfr");
    EXPECT_STREQ("1 1 W :Obstacle found, aborted.", rover.CurrentState().c_str());
    rover.SendSequentialCommand("rbl");
    EXPECT_STREQ("1 0 W", rover.CurrentState().c_str());
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
  plateau.GetPosition(-1, 0, pos_x, pos_y);
  EXPECT_EQ(5, pos_x);
  EXPECT_EQ(0, pos_y);
  plateau.GetPosition(5, -1, pos_x, pos_y);
  EXPECT_EQ(5, pos_x);
  EXPECT_EQ(5, pos_y);
}

TEST(PlateauTest, CanSetObstaclePositionAndQueryExsitsObstacle) {
  Plateau plateau(5, 5);
  int pos_x = 0;
  int pos_y = 0;
  plateau.SetObstacle(1, 2);
  EXPECT_TRUE(plateau.IsExistObstacle(1, 2));
  EXPECT_FALSE(plateau.IsExistObstacle(2, 2));
  
  plateau.SetObstacle(2, 2);
  EXPECT_TRUE(plateau.IsExistObstacle(1, 2));
  EXPECT_TRUE(plateau.IsExistObstacle(2, 2));
  EXPECT_FALSE(plateau.IsExistObstacle(2, 3));
}