// https://leetcode-cn.com/problems/length-of-last-word/
#include <string>
using namespace std;

class Solution
{
public:
  int lengthOfLastWord(string s)
  {
    int cnt = 0;
    int flag = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
      if (flag == 0 && s[i] == ' ')
      {
        continue;
      }
      if (s[i] != ' ')
      {
        flag = 1;
        cnt++;
      }
      else
      {
        break;
      }
    }
    return cnt;
  }
};

#include "gtest/gtest.h"

TEST(leetcode58, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_EQ(5, solution.lengthOfLastWord("Hello World"));
}

TEST(leetcode58, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_EQ(0, solution.lengthOfLastWord(" "));
}