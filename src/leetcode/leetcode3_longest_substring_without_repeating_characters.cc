// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#include <array>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    array<int, 128> last;
    fill(last.begin(), last.end(), -1);
    int res = 0, start = 0;
    for (int i = 0; i < s.length(); i++)
    {
      int index = s[i];
      start = max(start, last[index] + 1);
      res = max(res, i - start + 1);
      last[index] = i;
    }

    return res;
  }
};

#include "gtest/gtest.h"

TEST(leetcode3, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_EQ(3, solution.lengthOfLongestSubstring("abcabcbb"));
}

TEST(leetcode3, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_EQ(1, solution.lengthOfLongestSubstring("bbbbb"));
}

TEST(leetcode3, sampleInputByProblem3)
{
  Solution solution;
  ASSERT_EQ(3, solution.lengthOfLongestSubstring("pwwkew"));
}

TEST(leetcode3, sampleInputByProblem4)
{
  Solution solution;
  ASSERT_EQ(0, solution.lengthOfLongestSubstring(""));
}