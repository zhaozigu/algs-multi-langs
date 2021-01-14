// https://leetcode-cn.com/problems/reverse-string/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  void reverseString(vector<char> &s)
  {
    for (int i = 0; i < s.size() / 2; i++)
    {
      swap(s[i], s[s.size() - i - 1]);
    }

    // reverse(begin(s), end(s)); // slowly
    // swap(a, b) == (a ^= b;b ^= a;a ^= b)
  }
};

#include "gtest/gtest.h"

TEST(leetcode344, sampleInputByProblem1)
{
  vector<char> ins = {'h', 'e', 'l', 'l', 'o'};
  Solution solution;
  vector<char> outs = {'o', 'l', 'l', 'e', 'h'};
  solution.reverseString(ins);
  ASSERT_EQ(outs, ins);
}

TEST(leetcode344, sampleInputByProblem2)
{
  vector<char> ins = {'H', 'a', 'n', 'n', 'a', 'h'};
  Solution solution;
  vector<char> outs = {'h', 'a', 'n', 'n', 'a', 'H'};
  solution.reverseString(ins);
  ASSERT_EQ(outs, ins);
}