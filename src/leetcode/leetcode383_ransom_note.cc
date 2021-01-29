// https://leetcode-cn.com/problems/ransom-note/
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
  bool canConstruct(string ransomNote, string magazine)
  {
    vector<int> hash(256);
    for (int i = 0; i < magazine.size(); i++)
    {
      ++hash[magazine[i]];
    }

    for (int i = 0; i < ransomNote.size(); i++)
    {
      if (hash[ransomNote[i]])
      {
        --hash[ransomNote[i]];
      }
      else
      {
        return false;
      }
    }

    return true;
  }
};

#include "gtest/gtest.h"

TEST(leetcode383, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_FALSE(solution.canConstruct("a", "b"));
}

TEST(leetcode383, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_FALSE(solution.canConstruct("aa", "ab"));
}

TEST(leetcode383, sampleInputByProblem3)
{
  Solution solution;
  ASSERT_TRUE(solution.canConstruct("aa", "aab"));
}