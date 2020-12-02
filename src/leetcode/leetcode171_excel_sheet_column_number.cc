// https://leetcode-cn.com/problems/excel-sheet-column-number/
#include <string>
using namespace std;

class Solution
{
public:
  int titleToNumber(string s)
  {
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
      ans = ans * 26 + s[i] - 'A' + 1;
    }
    return ans;
  }
};

#include "gtest/gtest.h"

TEST(leetcode171, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_EQ(1, solution.titleToNumber("A"));
  ASSERT_EQ(28, solution.titleToNumber("AB"));
  ASSERT_EQ(701, solution.titleToNumber("ZY"));
}