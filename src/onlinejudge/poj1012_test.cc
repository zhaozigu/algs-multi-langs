#include "gtest/gtest.h"
#include "poj1012.hpp"

TEST(testPoj1012, sampleInputByProblem)
{
  Solve solve;
  EXPECT_EQ(5, solve.Survivor(3));
  EXPECT_EQ(30, solve.Survivor(4));
}