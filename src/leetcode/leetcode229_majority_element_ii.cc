// https://leetcode-cn.com/problems/majority-element-ii/
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    vector<int> res;
    int x = 0, y = 0, cx = 0, cy = 0, count = 0;

    for (auto num : nums)
    {
      if ((cx == 0 || num == x) && num != y)
      {
        ++cx, x = num;
      }
      else if (cy == 0 || num == y)
      {
        ++cy, y = num;
      }
      else
      {
        --cx, --cy;
      }
    }

    for (auto num : nums)
    {
      if (x == num)
      {
        ++count;
      }
    }

    if (count > nums.size() / 3)
    {
      res.push_back(x);
    }

    count = 0;
    for (auto num : nums)
    {
      if (y == num)
      {
        ++count;
      }
    }

    if (count > nums.size() / 3 && x != y)
    {
      res.push_back(y);
    }

    return res;
  }
};

#include "gtest/gtest.h"

TEST(leetcode229, sampleInputByProblem1)
{
  Solution solution;
  vector<int> ins = {3, 2, 3};
  vector<int> outs = {3};
  ASSERT_EQ(outs, solution.majorityElement(ins));
}

TEST(leetcode229, sampleInputByProblem2)
{
  Solution solution;
  vector<int> ins = {1};
  vector<int> outs = {1};
  ASSERT_EQ(outs, solution.majorityElement(ins));
}

TEST(leetcode229, sampleInputByProblem3)
{
  Solution solution;
  vector<int> ins = {1, 2};
  vector<int> outs = {1, 2};
  ASSERT_EQ(outs, solution.majorityElement(ins));
}