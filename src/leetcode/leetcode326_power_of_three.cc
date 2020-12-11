// https://leetcode-cn.com/problems/power-of-three/
#include <cmath>

class Solution
{
public:
  bool isPowerOfThree(int n)
  {
    if (n <= 0)
    {
      return false;
    }
    return pow(3, (round)(log(n) / log(3))) == n;
  }
};

#include "gtest/gtest.h"

TEST(leetcode326, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_TRUE(solution.isPowerOfThree(27));
}

TEST(leetcode326, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_FALSE(solution.isPowerOfThree(0));
}

TEST(leetcode326, sampleInputByProblem3)
{
  Solution solution;
  ASSERT_TRUE(solution.isPowerOfThree(9));
}

TEST(leetcode326, sampleInputByProblem4)
{
  Solution solution;
  ASSERT_FALSE(solution.isPowerOfThree(45));
}