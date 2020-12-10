//https://leetcode-cn.com/problems/power-of-two/
#include <cmath>

class Solution
{
public:
  bool isPowerOfTwo(int n)
  {
    if (n <= 0)
    {
      return false;
    }
    return pow(2, (round)(log(n) / log(2))) == n;
  }
};

#include "gtest/gtest.h"

TEST(leetcode231, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_TRUE(solution.isPowerOfTwo(1));
}

TEST(leetcode231, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_TRUE(solution.isPowerOfTwo(16));
}

TEST(leetcode231, sampleInputByProblem3)
{
  Solution solution;
  ASSERT_FALSE(solution.isPowerOfTwo(3));
}

TEST(leetcode231, sampleInputByProblem4)
{
  Solution solution;
  ASSERT_TRUE(solution.isPowerOfTwo(4));
}

TEST(leetcode231, sampleInputByProblem5)
{
  Solution solution;
  ASSERT_FALSE(solution.isPowerOfTwo(5));
}