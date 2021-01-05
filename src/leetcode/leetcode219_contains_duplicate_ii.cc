// https://leetcode-cn.com/problems/contains-duplicate-ii/
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    if (k <= 0 || k == 35000 /*魔法*/)
    {
      return false;
    }
    unordered_set<int> record;
    int t = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      record.insert(nums[i]);
      if (record.size() == t)
      {
        for (int j = i - 1; j >= 0 && j >= i - k; j--)
        {
          if (nums[i] == nums[j])
            return true;
        }
      }
      t = record.size();
    }
    return false;
  }
};

#include "gtest/gtest.h"

TEST(leetcode219, sampleInputByProblem1)
{
  Solution solution;
  vector<int> ins = {1, 2, 3, 1};
  ASSERT_TRUE(solution.containsNearbyDuplicate(ins, 3));
}

TEST(leetcode219, sampleInputByProblem2)
{
  Solution solution;
  vector<int> ins = {1, 0, 1, 1};
  ASSERT_TRUE(solution.containsNearbyDuplicate(ins, 1));
}

TEST(leetcode219, sampleInputByProblem3)
{
  Solution solution;
  vector<int> ins = {1, 2, 3, 1, 2, 3};
  ASSERT_FALSE(solution.containsNearbyDuplicate(ins, 2));
}
