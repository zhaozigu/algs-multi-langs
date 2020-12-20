// https://leetcode-cn.com/problems/single-number-ii/
#include <vector>
using namespace std;

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    int a = 0, b = 0;
    for (auto x : nums)
    {
      b = (b ^ x) & ~a;
      a = (a ^ x) & ~b;
    }
    return b;
  }
};

#include "gtest/gtest.h"

TEST(leetcode137, sampleInputByProblem1)
{
  Solution solution;
  vector<int> ins = {2, 2, 3, 2};
  ASSERT_EQ(3, solution.singleNumber(ins));
}

TEST(leetcode137, sampleInputByProblem2)
{
  Solution solution;
  vector<int> ins = {0, 1, 0, 1, 0, 1, 99};
  ASSERT_EQ(99, solution.singleNumber(ins));
}