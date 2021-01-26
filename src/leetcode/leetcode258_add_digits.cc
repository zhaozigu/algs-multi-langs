// https://leetcode-cn.com/problems/add-digits/
class Solution
{
public:
  int addDigits(int num)
  {
    return (num - 1) % 9 + 1;
  }
};

#include "gtest/gtest.h"

TEST(leetcode258, smapleInputByProblem)
{
  Solution solution;
  ASSERT_EQ(2, solution.addDigits(38));
}