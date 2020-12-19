// https://leetcode-cn.com/problems/missing-number/
#include <vector>
using namespace std;

class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    int res = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
      res ^= nums[i];
      res ^= i;
    }
    return res;
  }
};

#include "gtest/gtest.h"

TEST(leetcode268, sampleInputByProblem1)
{
  Solution solution;
  vector<int> ins = {3, 0, 1};
  ASSERT_EQ(2, solution.missingNumber(ins));
}

TEST(leetcode268, sampleInputByProblem2)
{
  Solution solution;
  vector<int> ins = {0, 1};
  ASSERT_EQ(2, solution.missingNumber(ins));
}

TEST(leetcode268, sampleInputByProblem3)
{
  Solution solution;
  vector<int> ins = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  ASSERT_EQ(8, solution.missingNumber(ins));
}