// https://leetcode-cn.com/problems/integer-break/
#include <vector>
using namespace std;

class Solution
{
public:
  int integerBreak(int n)
  {
    if (n == 2)
    {
      return 1;
    }
    else if (n == 3)
    {
      return 1;
    }
    else
    {
      int a = 1;
      while (n > 4)
      {
        n -= 3;
        a *= 3;
      }
      return a * n;
    }
  }
};

#include "gtest/gtest.h"

TEST(leetcode343, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_EQ(1, solution.integerBreak(2));
}

TEST(leetcode343, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_EQ(36, solution.integerBreak(10));
}