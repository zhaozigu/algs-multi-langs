#include "gtest/gtest.h"
#include "poj1363.hpp"

TEST(testPoj1363, sampleInputByProblem1)
{
  Solve solve;
  int input[5] = {1, 2, 3, 4, 5};
  EXPECT_EQ(5, solve.GetPopNum(input, 5));
}

TEST(testPoj1363, sampleInputByProblem2)
{
  Solve solve;
  int input[5] = {5, 4, 1, 2, 3};
  EXPECT_GT(5, solve.GetPopNum(input, 5));
}

TEST(testPoj1363, sampleInputByProblem3)
{
  Solve solve;
  int input[6] = {6, 5, 4, 3, 2, 1};
  EXPECT_EQ(6, solve.GetPopNum(input, 6));
}
