// https://leetcode-cn.com/problems/rotate-array/
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();
    k %= n;
    for (int i = 0; i <= (n - 1 - k) / 2; i++)
    {
      swap(nums[i], nums[n - 1 - k - i]);
    }
    for (int i = n - k; i <= (n - 1 + n - k) / 2; i++)
    {
      swap(nums[i], nums[n - 1 + n - k - i]);
    }
    for (int i = 0; i <= (n - 1) / 2; i++)
    {
      swap(nums[i], nums[n - 1 - i]);
    }
  }
};

#include "gtest/gtest.h"

TEST(leetcode189, sampleInputByProblem1)
{
  Solution solution;
  vector<int> ins = {1, 2, 3, 4, 5, 6, 7};
  vector<int> outs = {5, 6, 7, 1, 2, 3, 4};
  solution.rotate(ins, 3);
  ASSERT_EQ(outs, ins);
}

TEST(leetcode189, sampleInputByProblem2)
{
  Solution solution;
  vector<int> ins = {-1, -100, 3, 99};
  vector<int> outs = {3, 99, -1, -100};
  solution.rotate(ins, 2);
  ASSERT_EQ(outs, ins);
}