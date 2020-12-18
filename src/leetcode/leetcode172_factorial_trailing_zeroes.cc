// https://leetcode-cn.com/problems/factorial-trailing-zeroes/
class Solution
{
public:
  int trailingZeroes(int n)
  {
    int cnt = 0;
    while (n != 0)
    {
      cnt += n / 5;
      n /= 5;
    }
    return cnt;
  }
};

#include "gtest/gtest.h"

TEST(leetcode172, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_EQ(0, solution.trailingZeroes(3));
}

TEST(leetcode172, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_EQ(1, solution.trailingZeroes(5));
}

TEST(leetcode172, sampleInputByProblem3)
{
  Solution solution;
  ASSERT_EQ(0, solution.trailingZeroes(0));
}