// https://leetcode-cn.com/problems/valid-sudoku/
#include <vector>
#include <array>

using namespace std;

class Solution
{
public:
  bool isValidSudoku(vector<vector<char>> &board)
  {
    array<int, 9> rows{}, cols{}, grids{};
    for (int r = 0; r < 9; ++r)
    {
      for (int c = 0; c < 9; ++c)
      {
        if (board[r][c] == '.')
        {
          continue;
        }
        int p = (r / 3) * 3 + (c / 3);
        int v = board[r][c] - '0';
        int m = 1 << v;
        if ((rows[r] & m) || (cols[c] & m) || (grids[p] & m))
        {
          return false;
        }
        rows[r] |= m;
        cols[c] |= m;
        grids[p] |= m;
      }
    }
    return true;
  }
};

#include "gtest/gtest.h"

TEST(leetcode36, sampleInputByProblem1)
{
  Solution solution;
  vector<vector<char>> board = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  ASSERT_TRUE(solution.isValidSudoku(board));
}

TEST(leetcode36, sampleInputByProblem2)
{
  Solution solution;
  vector<vector<char>> board = {
      {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  ASSERT_FALSE(solution.isValidSudoku(board));
}