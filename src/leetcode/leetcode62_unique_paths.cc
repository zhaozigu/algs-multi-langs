// https://leetcode-cn.com/problems/unique-paths/
class Solution
{
public:
  int uniquePaths(int m, int n)
  {
    int a[100][100];
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == 0 || j == 0)
          a[i][j] = 1;
        else
          a[i][j] = a[i - 1][j] + a[i][j - 1];
      }
    }
    return a[m - 1][n - 1];
  }
};

#include "gtest/gtest.h"

TEST(leetcode62, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_EQ(28, solution.uniquePaths(3, 7));
}

TEST(leetcode62, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_EQ(3, solution.uniquePaths(3, 2));
}

TEST(leetcode62, sampleInputByProblem3)
{
  Solution solution;
  ASSERT_EQ(28, solution.uniquePaths(7, 3));
}

TEST(leetcode62, sampleInputByProblem4)
{
  Solution solution;
  ASSERT_EQ(6, solution.uniquePaths(3, 3));
}