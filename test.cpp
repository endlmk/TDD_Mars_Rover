#include <gtest/gtest.h>
#include "MarsRover.h"

TEST(MarsRoverTest, CanOutputCurrentState) {
  MarsRover rover(1, 2, 'N');
  EXPECT_STREQ("1 2 N", rover.CurrentState().c_str());
}
