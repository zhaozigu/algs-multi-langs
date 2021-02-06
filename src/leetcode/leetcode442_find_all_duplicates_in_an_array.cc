//
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<int> findDuplicates(vector<int> &nums)
  {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
      int num = abs(nums[i]);
      if (nums[num - 1] < 0)
        result.push_back(num);
      else
        nums[num - 1] = 0 - nums[num - 1];
    }
    return result;
  }
};

#include "gtest/gtest.h"

TEST(leetcode442, sampleInputByProblem1)
{
  Solution solution;
  vector<int> outs = {2, 3};
  vector<int> ins = {4, 3, 2, 7, 8, 2, 3, 1};
  ASSERT_EQ(outs, solution.findDuplicates(ins));
}