// https://leetcode-cn.com/problems/counting-bits/
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> countBits(int num)
  {
    vector<int> v(num + 1);
    v[0] = 0;
    for (int i = 1; i < num + 1; i++)
    {
      v[i] = v[i >> 1] + (i & 1);
    }
    return v;
  }
};

#include "gtest/gtest.h"

TEST(leetcode338, SampleInputByProblem1)
{
  Solution solution;
  vector<int> out = {0, 1, 1};
  ASSERT_EQ(out, solution.countBits(2));
}

TEST(leetcode338, SampleInputByProblem2)
{
  Solution solution;
  vector<int> out = {0, 1, 1, 2, 1, 2};
  ASSERT_EQ(out, solution.countBits(5));
}