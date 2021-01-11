// https://leetcode-cn.com/problems/longest-common-prefix/
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    if (strs.size() == 0)
    {
      return "";
    }

    string s = strs[0];
    for (int i = 1; i < strs.size(); i++)
    {
      for (int j = 0; j < s.length(); j++)
      {
        if (s[j] != strs[i][j])
        {
          s = s.substr(0, j);
          break;
        }
      }
    }
    return s;
  }
};

#include "gtest/gtest.h"

TEST(leetcode14, sampleInputByProblem1)
{
  Solution solution;
  vector<string> strs = {"flower", "flow", "flight"};
  ASSERT_EQ("fl", solution.longestCommonPrefix(strs));
}

TEST(leetcode14, sampleInputByProblem2)
{
  Solution solution;
  vector<string> strs = {"dog", "racecar", "car"};
  ASSERT_EQ("", solution.longestCommonPrefix(strs));
}