// https://leetcode-cn.com/problems/nim-game/

class Solution
{
public:
  bool canWinNim(int n)
  {
    return n % 4;
  }
};

#include "gtest/gtest.h"

TEST(leetcode292, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_EQ(false, solution.canWinNim(4));
}

TEST(leetcode292, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_EQ(true, solution.canWinNim(1));
}

TEST(leetcode292, sampleInputByProblem3)
{
  Solution solution;
  ASSERT_EQ(true, solution.canWinNim(2));
}
