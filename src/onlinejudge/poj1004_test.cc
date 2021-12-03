#include <cmath>
#include "gtest/gtest.h"
#include "poj1004.hpp"

TEST(testPoj1004, sampleInputByProblem)
{
  double ins[] = {
      100.00,
      489.12,
      12454.12,
      1234.10,
      823.05,
      109.20,
      5.27,
      1542.25,
      839.18,
      83.99,
      1295.01,
      1.75,
      NAN};
  Solve solve;
  for (int i = 0; !std::isnan(ins[i]); i++)
  {
    solve.Add(ins[i]);
  }
  EXPECT_EQ(1581.42, static_cast<int>(solve.GetAvg() * 100) / 100.0);
}