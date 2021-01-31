// https://leetcode-cn.com/problems/number-complement/
class Solution
{
public:
  int findComplement(int num)
  {
    int temp = num, c = 0;
    while (temp > 0)
    {
      temp >>= 1;
      c = (c << 1) + 1;
    }
    return num ^ c;
  }
};

#include "gtest/gtest.h"

TEST(leetcode476, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_EQ(2, solution.findComplement(5));
}

TEST(leetcode476, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_EQ(0, solution.findComplement(1));
}