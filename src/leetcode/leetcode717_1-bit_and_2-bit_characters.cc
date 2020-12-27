// https://leetcode-cn.com/problems/1-bit-and-2-bit-characters/
#include <vector>
using namespace std;

class Solution
{
public:
  bool isOneBitCharacter(vector<int> &bits)
  {
    int index = 0;
    while (index < bits.size() - 1)
    {
      index += bits[index] + 1;
    }

    return index == bits.size() - 1;
  }
};

#include "gtest/gtest.h"

TEST(leetcode717, sampleInputByProblem1)
{
  Solution solution;
  vector<int> ins = {1, 0, 0};
  ASSERT_TRUE(solution.isOneBitCharacter(ins));
}

TEST(leetcode717, sampleInputByProblem2)
{
  Solution solution;
  vector<int> ins = {1, 1, 1, 0};
  ASSERT_FALSE(solution.isOneBitCharacter(ins));
}

TEST(leetcode717, SingleBitTestOne)
{
  Solution solution;
  vector<int> ins = {1};
  ASSERT_TRUE(solution.isOneBitCharacter(ins));
}

TEST(leetcode717, SingleBitTestZero)
{
  Solution solution;
  vector<int> ins = {0};
  ASSERT_TRUE(solution.isOneBitCharacter(ins));
}