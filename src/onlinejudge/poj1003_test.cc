#include <cmath>
#include "gtest/gtest.h"
#include "poj1003.hpp"

TEST(testPoj1003, sampleInputByProblem)
{
  double ins[] = {1.00, 3.71, 0.04, 5.19, NAN};
  int ex_out[4] = {3, 61, 1, 273};
  Solve solve;
  for (int i = 0; !std::isnan(ins[i]); i++)
  {
    ASSERT_EQ(ex_out[i], solve.GetCardNum(ins[i]));
  }
}