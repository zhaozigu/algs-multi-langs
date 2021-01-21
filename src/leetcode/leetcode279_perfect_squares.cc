// https://leetcode-cn.com/problems/perfect-squares/
#include <vector>
#include <algorithm>
#include <limits>

#include <cmath>
using namespace std;

class Solution
{
public:
  int numSquares(int n)
  {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
      int temp = numeric_limits<int>::max();
      for (int j = 1; j * j <= i; j++)
      {
        temp = min(temp, dp[i - j * j]);
      }
      dp[i] = temp + 1;
    }
    return dp[n];
  }

  int numSquaresTheory(int n)
  {
    while (n % 4 == 0)
    {
      n /= 4;
    }

    if (n % 8 == 7)
    {
      return 4;
    }
    // 是否可以由一个数的平方或者两个数平方的和组成
    int a = 0;
    while ((a * a) <= n)
    {
      int b = sqrt((n - a * a));
      if (a * a + b * b == n)
      {
        if (a != 0 && b != 0)
        {
          return 2;
        }
        else
        {
          return 1;
        }
      }
      a++;
    }
    // 如果不行 返回3
    return 3;
  }
};

#include "gtest/gtest.h"

TEST(leetcode279, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_EQ(3, solution.numSquares(12)); // 4 + 4 + 4
  ASSERT_EQ(3, solution.numSquares(12)); // 4 + 4 + 4
}

TEST(leetcode279, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_EQ(2, solution.numSquares(13)); // 4 + 9
}

TEST(leetcode279, sampleInputByProblemTheory1)
{
  Solution solution;
  ASSERT_EQ(3, solution.numSquaresTheory(12)); // 4 + 4 + 4
}

TEST(leetcode279, sampleInputByProblemTheory2)
{
  Solution solution;
  ASSERT_EQ(2, solution.numSquaresTheory(13)); // 4 + 9
}