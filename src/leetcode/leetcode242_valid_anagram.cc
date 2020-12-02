// https://leetcode-cn.com/problems/valid-anagram/
#include <string>
using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    int a[26] = {0};
    if (s.length() != t.length())
    {
      return 0;
    }
    for (int i = 0; i < s.length(); i++)
    {
      a[s[i] - 'a']++;
    }
    for (int i = 0; i < t.length(); i++)
    {
      a[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
      if (a[i] != 0)
      {
        return 0;
      }
    }
    return 1;
  }
};

#include "gtest/gtest.h"

TEST(leetcode242, sampleInputByProblem)
{
  Solution solution;
  ASSERT_EQ(true, solution.isAnagram("anagram", "nagaram"));
  ASSERT_EQ(false, solution.isAnagram("rat", "car"));
}
