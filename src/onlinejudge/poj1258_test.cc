#include "gtest/gtest.h"
#include "poj1258.hpp"

TEST(testPoj1258, sampleInputByProblem)
{
  constexpr int n = 4;
  Solve solve(n);

  int inputs[n][n] = {
      {0, 4, 9, 21},
      {4, 0, 8, 17},
      {9, 8, 0, 16},
      {21, 17, 16, 0}};

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      solve[i][j] = inputs[i][j];
    }
  }

  EXPECT_EQ(28, solve.Prim());
}