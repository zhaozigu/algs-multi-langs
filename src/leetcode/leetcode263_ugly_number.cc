// https://leetcode-cn.com/problems/ugly-number/
class Solution
{
public:
  bool isUgly(int num)
  {
    if (num <= 0)
    {
      return false;
    }
    bool flag = false;
    while (num != 1)
    {
      flag = false;

      if (num % 2 == 0)
      {
        num /= 2;
        flag = true;
      }
      if (num % 3 == 0)
      {
        num /= 3;
        flag = true;
      }
      if (num % 5 == 0)
      {
        num /= 5;
        flag = true;
      }

      if (!flag)
      {
        return false;
      }
    }

    return true;
  }
};

#include "gtest/gtest.h"

TEST(leetcode263, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_TRUE(solution.isUgly(6));
}

TEST(leetcode263, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_TRUE(solution.isUgly(8));
}

TEST(leetcode263, sampleInputByProblem3)
{
  Solution solution;
  ASSERT_FALSE(solution.isUgly(14));
}

TEST(leetcode263, sampleInputByZero)
{
  Solution solution;
  ASSERT_FALSE(solution.isUgly(0));
}