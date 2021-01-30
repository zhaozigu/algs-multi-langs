// https://leetcode-cn.com/problems/max-consecutive-ones/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int findMaxConsecutiveOnes(vector<int> &nums)
  {
    int result = 0;
    int start = -1;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 1)
      {
        result = max(result, i - start);
      }
      else
      {
        start = i;
      }
    }
    return result;
  }
};

#include "gtest/gtest.h"

TEST(leetcode485, sampleInputByProblem)
{
  Solution solution;
  vector<int> ins = {1, 1, 0, 1, 1, 1};
  ASSERT_EQ(3, solution.findMaxConsecutiveOnes(ins));
}