#include <vector>
using namespace std;

class Solution
{
  int cnt = 0;

public:
  int totalNQueens(int n)
  {
    vector<int> pos(n);
    dfs(pos, n, 0);
    return cnt;
  }

private:
  void dfs(vector<int> &pos, int n, int row)
  {
    if (row == n)
    {
      cnt++;
      return;
    }
    for (pos[row] = 0; pos[row] < n; pos[row]++)
    {
      if (issafe(pos, n, row))
      {
        dfs(pos, n, row + 1);
      }
    }
  }

  bool issafe(vector<int> &pos, int n, int row)
  {
    for (int i = 0; i < row; i++)
    {
      if (pos[i] == pos[row] || abs(i - row) == abs(pos[i] - pos[row]))
        return false;
    }
    return true;
  }
};

#include "gtest/gtest.h"

TEST(leetcode52, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_EQ(2, solution.totalNQueens(4));
}

TEST(leetcode52, sampleInputByProblem12)
{
  Solution solution;
  ASSERT_EQ(1, solution.totalNQueens(1));
}