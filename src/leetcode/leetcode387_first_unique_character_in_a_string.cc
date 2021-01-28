// https://leetcode-cn.com/problems/first-unique-character-in-a-string/
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int firstUniqChar(string s)
  {
    unordered_map<int, int> frequency;
    for (char ch : s)
    {
      ++frequency[ch];
    }
    for (int i = 0; i < s.size(); ++i)
    {
      if (frequency[s[i]] == 1)
      {
        return i;
      }
    }
    return -1;
  }
};

#include "gtest/gtest.h"

TEST(leetcode387, sampleInputByProblem)
{
  Solution solution;
  ASSERT_EQ(0, solution.firstUniqChar("leetcode"));
  ASSERT_EQ(2, solution.firstUniqChar("loveleetcode"));
}
