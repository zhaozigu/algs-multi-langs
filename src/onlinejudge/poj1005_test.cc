#include "gtest/gtest.h"
#include "poj1005.hpp"

TEST(testPoj1005, sampleInputByProblem)
{
  Solve solve;
  ASSERT_EQ(1, solve.Calc(1.0, 1.0));
  ASSERT_EQ(20, solve.Calc(25.0, 0.0));
}