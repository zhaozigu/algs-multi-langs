// https://leetcode-cn.com/problems/two-sum/
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    vector<int> v(2);
    for (int i = 0; i < nums.size(); i++)
    {
      for (int j = i + 1; j < nums.size(); j++)
      {
        if (nums[i] + nums[j] == target)
        {
          v[0] = i;
          v[1] = j;
        }
      }
    }
    return v;
  }
};

#include "gtest/gtest.h"

TEST(leetcode1, sampleInputByProblem1)
{
  Solution solution;
  vector<int> ins = {2, 7, 11, 15};
  vector<int> outs = {0, 1};
  ASSERT_EQ(outs, solution.twoSum(ins, 9));
}

TEST(leetcode1, sampleInputByProblem2)
{
  Solution solution;
  vector<int> ins = {3, 2, 4};
  vector<int> outs = {1, 2};
  ASSERT_EQ(outs, solution.twoSum(ins, 6));
}

TEST(leetcode1, sampleInputByProblem3)
{
  Solution solution;
  vector<int> ins = {3, 3};
  vector<int> outs = {0, 1};
  ASSERT_EQ(outs, solution.twoSum(ins, 6));
}