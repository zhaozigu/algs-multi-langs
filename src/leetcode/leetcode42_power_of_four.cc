// https://leetcode-cn.com/problems/power-of-four/
class Solution
{
public:
  bool isPowerOfFour(int n)
  {
    return (n <= 0 || n & (n - 1)) ? false : n % 3 == 1;
  }
};

#include "gtest/gtest.h"

TEST(leetcode42, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_TRUE(solution.isPowerOfFour(16));
}

TEST(leetcode42, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_FALSE(solution.isPowerOfFour(5));
}

TEST(leetcode42, sampleInputByProblem3)
{
  Solution solution;
  ASSERT_TRUE(solution.isPowerOfFour(1));
}