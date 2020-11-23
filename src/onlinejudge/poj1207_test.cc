#include <map>
#include <utility>

using namespace std;

#include "gtest/gtest.h"
#include "poj1207.hpp"

TEST(testPoj1207, sampleInputByProblem)
{
  Solve solve;
  map<pair<int, int>, int> in = {
      {make_pair(1, 10), 20},
      {make_pair(100, 200), 125},
      {make_pair(201, 210), 89},
      {make_pair(900, 1000), 174}};

  for (auto &i : in)
  {
    EXPECT_EQ(i.second, solve.MaxCycleLength(i.first.first, i.first.second));
  }
}