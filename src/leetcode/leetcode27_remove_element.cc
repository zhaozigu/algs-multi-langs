// https://leetcode-cn.com/problems/remove-element/
#include <vector>
using namespace std;

class Solution
{
public:
  int removeElement(vector<int> &nums, int val)
  {
    int len = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != val)
      {
        nums[len++] = nums[i];
      }
    }

    return len;
  }
};

#include "gtest/gtest.h"

TEST(leetcode27, sampleInputByProblem1)
{
  Solution solution;
  vector<int> in = {3, 2, 2, 3};
  vector<int> out = {2, 2};
  ASSERT_EQ(2, solution.removeElement(in, 3));
}

TEST(leetcode27, sampleInputByProblem2)
{
  Solution solution;
  vector<int> in = {0, 1, 2, 2, 3, 0, 4, 2};
  vector<int> out = {0, 1, 4, 0, 3};
  ASSERT_EQ(5, solution.removeElement(in, 2));
}