// https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
  vector<int> findDisappearedNumbers(vector<int> &nums)
  {
    for (int i = 0; i < nums.size(); i++)
    {
      nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
    }
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] > 0)
        res.push_back(i + 1);
    }

    return res;
  }
};

#include "gtest/gtest.h"

TEST(leetcode448, sampleInputByProblem)
{
  vector<int> ins = {4,
                     3,
                     2,
                     7,
                     8,
                     2,
                     3,
                     1};
  Solution solution;
  vector<int> outs = {5, 6};
  ASSERT_EQ(outs, solution.findDisappearedNumbers(ins));
}