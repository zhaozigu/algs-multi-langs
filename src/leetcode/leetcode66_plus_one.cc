// https://leetcode-cn.com/problems/plus-one/
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> plusOne(vector<int> &digits)
  {
    for (int i = digits.size() - 1; i >= 0; i--)
    {
      if (digits[i] != 9)
      {
        digits[i] = digits[i] + 1;
        return digits;
      }
      else
      {
        digits[i] = 0;
      }
    }
    digits.insert(digits.begin(), 1);

    return digits;
  }
};

#include "gtest/gtest.h"

TEST(leetcode66, sampleInputByProblem1)
{
  Solution solution;
  vector<int> in = {1, 2, 3};
  vector<int> out = {1, 2, 4};
  ASSERT_EQ(out, solution.plusOne(in));
}

TEST(leetcode66, sampleInputByProblem2)
{
  Solution solution;
  vector<int> in = {4, 3, 2, 1};
  vector<int> out = {4, 3, 2, 2};
  ASSERT_EQ(out, solution.plusOne(in));
}