// https://leetcode-cn.com/problems/search-insert-position/
#include <vector>
using namespace std;

class Solution
{
public:
  int searchInsert(vector<int> &nums, int target)
  {
    int left = 0, right = nums.size() - 1;

    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (target > nums[mid])
      {
        left = mid + 1;
      }
      else if (target < nums[mid])
      {
        right = mid - 1;
      }
      else
      {
        return mid;
      }
    }
    return left;
  }
};

#include "gtest/gtest.h"

TEST(leetcode35, sampleInputByProblem1)
{
  Solution solution;
  vector<int> ins = {1, 3, 5, 6};
  ASSERT_EQ(2, solution.searchInsert(ins, 5));
}

TEST(leetcode35, sampleInputByProblem2)
{
  Solution solution;
  vector<int> ins = {1, 3, 5, 6};
  ASSERT_EQ(1, solution.searchInsert(ins, 2));
}

TEST(leetcode35, sampleInputByProblem3)
{
  Solution solution;
  vector<int> ins = {1, 3, 5, 6};
  ASSERT_EQ(4, solution.searchInsert(ins, 7));
}

TEST(leetcode35, sampleInputByProblem4)
{
  Solution solution;
  vector<int> ins = {1, 3, 5, 6};
  ASSERT_EQ(0, solution.searchInsert(ins, 0));
}

TEST(leetcode35, sampleInputByProblem5)
{
  Solution solution;
  vector<int> ins = {1};
  ASSERT_EQ(0, solution.searchInsert(ins, 0));
}