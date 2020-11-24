#include "gtest/gtest.h"
#include "poj1338.hpp"

TEST(testPoj1338, sampleInputByProblem)
{
  Solve solve(1500);
  EXPECT_EQ(1, solve[1]);
  EXPECT_EQ(2, solve[2]);
  EXPECT_EQ(10, solve[9]);
}
