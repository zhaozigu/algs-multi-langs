// https://leetcode-cn.com/problems/single-number/
#include <vector>
using namespace std;

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
      res ^= nums[i];
    }
    return res;
  }
};

#include "gtest/gtest.h"

TEST(leetcode136, sampleInputByProblem1)
{
  Solution solution;
  vector<int> ins = {2, 2, 1};
  ASSERT_EQ(1, solution.singleNumber(ins));
}

TEST(leetcode136, sampleInputByProblem2)
{
  Solution solution;
  vector<int> ins = {4, 1, 2, 1, 2};
  ASSERT_EQ(4, solution.singleNumber(ins));
}

TEST(leetcode136, sampleInputByProblem3)
{
  Solution solution;
  vector<int> ins = {1};
  ASSERT_EQ(1, solution.singleNumber(ins));
}