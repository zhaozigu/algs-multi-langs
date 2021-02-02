// https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> findAnagrams(string s, string p)
  {
    vector<int> res;
    int count[256] = {0};
    for (auto e : p)
    {
      ++count[(int)e];
    }

    int left = 0, right = 0, len = 0;

    while (right < s.size())
    {
      if (--count[(int)s[right++]] >= 0)
      {
        ++len;
        if (len == p.length())
          res.push_back(left);
      }
      if (right - left < p.length())
      {
        continue;
      }
      if (++count[(int)s[left++]] > 0)
      {
        --len;
      }
    }
    return res;
  }
};

#include "gtest/gtest.h"

TEST(leetcode438, sampleInputByProblem1)
{
  Solution solution;
  vector<int> outs = {0, 6};
  ASSERT_EQ(outs, solution.findAnagrams("cbaebabacd", "abc"));
}

TEST(leetcode438, sampleInputByProblem2)
{
  Solution solution;
  vector<int> outs = {0, 1, 2};
  ASSERT_EQ(outs, solution.findAnagrams("abab", "ab"));
}