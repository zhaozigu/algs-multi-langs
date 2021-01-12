// https://leetcode-cn.com/problems/implement-strstr/
#include <string>
using namespace std;

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    int len1 = haystack.length();
    int len2 = needle.length();
    if (len2 == 0)
    {
      return 0;
    }

    for (int i = 0; i <= len1 - len2; i++)
    {
      for (int j = 0; j < len2 && needle[j] == haystack[i + j]; j++)
      {
        if (j == len2 - 1)
          return i;
      }
    }
    return -1;
  }
};

#include "gtest/gtest.h"

TEST(leetcode28, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_EQ(2, solution.strStr("hello", "ll"));
}

TEST(leetcode28, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_EQ(-1, solution.strStr("aaaaa", "bba"));
}

TEST(leetcode28, sampleInputByProblem3)
{
  Solution solution;
  ASSERT_EQ(0, solution.strStr("", ""));
}