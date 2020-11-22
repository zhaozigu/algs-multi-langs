#include "gtest/gtest.h"
#include "poj1007.hpp"

TEST(testPoj1007, sampleInputByProblem)
{
  Solve solve;
  EXPECT_EQ(1, solve.Stat("AACEDGG"));
  EXPECT_EQ(6, solve.Stat("ZWQM"));
}