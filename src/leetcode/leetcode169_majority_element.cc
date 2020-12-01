// https://leetcode-cn.com/problems/majority-element/
#include <vector>
using std::vector;

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    int res = 0, cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (cnt == 0)
      {
        res = nums[i];
        ++cnt;
      }
      else
      {
        res == nums[i] ? cnt++ : cnt--;
      }
    }
    return res;
  }
};

#include "gtest/gtest.h"

TEST(leetcode169, sampleInputByProblem)
{
  Solution solution;
  std::vector<int> in = {3, 2, 3};
  ASSERT_EQ(3, solution.majorityElement(in));
}

TEST(leetcode169, sampleInputByProblem1)
{
  Solution solution;
  std::vector<int> in = {2, 2, 1, 1, 1, 2, 2};
  ASSERT_EQ(2, solution.majorityElement(in));
}