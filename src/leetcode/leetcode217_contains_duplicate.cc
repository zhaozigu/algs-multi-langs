// https://leetcode-cn.com/problems/contains-duplicate/
#include <vector>
#include <set>
#include <iterator>
using namespace std;

class Solution
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    return set<int>(begin(nums), end(nums)).size() != nums.size();
  }
};

#include "gtest/gtest.h"

TEST(leetcode217, sampleInputByProblem1)
{
  vector<int> vec = {1, 2, 3, 1};
  Solution solution;
  ASSERT_EQ(true, solution.containsDuplicate(vec));
}

TEST(leetcode217, sampleInputByProblem2)
{
  vector<int> vec = {1, 2, 3, 4};
  Solution solution;
  ASSERT_EQ(false, solution.containsDuplicate(vec));
}

TEST(leetcode217, sampleInputByProblem3)
{
  vector<int> vec = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  Solution solution;
  ASSERT_EQ(true, solution.containsDuplicate(vec));
}