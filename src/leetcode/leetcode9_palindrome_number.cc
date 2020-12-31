// https://leetcode-cn.com/problems/palindrome-number/
#include <limits>
#include <cmath>

using namespace std;

class Solution
{
public:
  bool isPalindrome(int x)
  {
    if (x < 0)
    {
      return false;
    }
    x = abs(x + 0.0);
    int help = 1;
    // 防止溢出
    while (x / help >= 10)
    {
      help *= 10;
    }

    while (x != 0)
    {
      if (x / help != x % 10)
      {
        return false;
      }
      x = (x % help) / 10;
      help /= 100;
    }
    return true;
  }
};

#include "gtest/gtest.h"

TEST(testIsPalindrome, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_TRUE(solution.isPalindrome(121));
}

TEST(testIsPalindrome, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_FALSE(solution.isPalindrome(-121));
  ASSERT_FALSE(solution.isPalindrome(-101));
}

TEST(testIsPalindrome, sampleInputByProblem3)
{
  Solution solution;
  ASSERT_FALSE(solution.isPalindrome(-101));
}