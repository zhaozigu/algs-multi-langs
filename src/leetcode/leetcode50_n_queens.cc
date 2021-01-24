// https://leetcode-cn.com/problems/n-queens/
#include <string>
#include <vector>
using namespace std;

class Solution
{
  vector<vector<string>> v;

public:
  vector<vector<string>> solveNQueens(int n)
  {
    vector<int> pos(n);
    dfs(pos, n, 0);
    return v;
  }

private:
  void dfs(vector<int> &pos, int n, int row)
  {
    if (row == n)
    {
      vector<string> temp(n, string(n, '.'));
      for (int i = 0; i < n; i++)
      {
        temp[i][pos[i]] = 'Q';
      }
      v.push_back(temp);
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
      if (pos[i] == pos[row] || abs(i - row) == abs(pos[i] - pos[row]))
        return false;
    return true;
  }
};

#include "gtest/gtest.h"

TEST(leetcode50, sampleInputByProblem1)
{
  Solution solution;
  vector<vector<string>> out = {
      {".Q..", "...Q", "Q...", "..Q."},
      {"..Q.", "Q...", "...Q", ".Q.."}};
  ASSERT_EQ(out, solution.solveNQueens(4));
}

TEST(leetcode50, sampleInputByProblem2)
{
  Solution solution;
  vector<vector<string>> out = {{"Q"}};
  ASSERT_EQ(out, solution.solveNQueens(1));
}