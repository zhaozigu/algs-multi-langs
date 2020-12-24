// https://leetcode-cn.com/problems/find-peak-element/
#include <vector>
using namespace std;

class Solution
{
public:
  int findPeakElement(vector<int> &nums)
  {
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] > nums[mid + 1])
      {
        right = mid;
      }
      else
      {
        left = mid + 1;
      }
    }

    return left;
  }
};

#include "gtest/gtest.h"

TEST(leetcode162, sampleInputByProblem1)
{
  Solution solution;
  vector<int> ins = {1, 2, 3, 1};
  ASSERT_EQ(2, solution.findPeakElement(ins));
}

TEST(leetcode162, sampleInputByProblem2)
{
  Solution solution;
  vector<int> ins = {1, 2, 1, 3, 5, 6, 4};
  ASSERT_EQ(5, solution.findPeakElement(ins));
}