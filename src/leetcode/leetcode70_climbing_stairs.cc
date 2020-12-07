// https://leetcode-cn.com/problems/climbing-stairs/
class Solution
{
public:
  int climbStairs(int n)
  {
    int f = 1, g = 1;
    for (int i = 2; i <= n; i++)
    {
      g = f + g;
      f = g - f;
    }
    return g;
  }
};

#include "gtest/gtest.h"

TEST(leetcode70, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_EQ(2, solution.climbStairs(2));
}

TEST(leetcode70, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_EQ(3, solution.climbStairs(3));
}
