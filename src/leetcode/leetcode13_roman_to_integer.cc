// https://leetcode-cn.com/problems/roman-to-integer/
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
  int romanToInt(string s)
  {
    int ans = 0;
    unordered_map<char, int> m = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    for (int i = 0; i < s.length() - 1; i++)
    {
      if (m[s[i]] >= m[s[i + 1]])
      {
        ans += m[s[i]];
      }
      else
      {
        ans -= m[s[i]];
      }
    }
    ans += m[s[s.length() - 1]];
    return ans;
  }
};

#include "gtest/gtest.h"

TEST(leetcode13, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_EQ(3, solution.romanToInt("III"));
}

TEST(leetcode13, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_EQ(4, solution.romanToInt("IV"));
}

TEST(leetcode13, sampleInputByProblem3)
{
  Solution solution;
  ASSERT_EQ(9, solution.romanToInt("IX"));
}

TEST(leetcode13, sampleInputByProblem4)
{
  Solution solution;
  ASSERT_EQ(58, solution.romanToInt("LVIII"));
}

TEST(leetcode13, sampleInputByProblem5)
{
  Solution solution;
  ASSERT_EQ(1994, solution.romanToInt("MCMXCIV"));
}