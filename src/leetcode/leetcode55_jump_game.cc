// https://leetcode-cn.com/problems/jump-game/
#include <vector>
using namespace std;

class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int distance = 0;
    for (int i = 0; i < nums.size() - 1 && i <= distance; i++)
    {
      distance = max(distance, i + nums[i]);
    }
    return distance >= (nums.size() - 1);
  }
};

#include "gtest/gtest.h"

TEST(leetcode55, sampleInputByProblem1)
{
  Solution solution;
  vector<int> ins = {2, 3, 1, 1, 4};
  ASSERT_TRUE(solution.canJump(ins));
}

TEST(leetcode55, sampleInputByProblem2)
{
  Solution solution;
  vector<int> ins = {3, 2, 1, 0, 4};
  ASSERT_FALSE(solution.canJump(ins));
}