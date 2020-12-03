// https://leetcode-cn.com/problems/number-of-1-bits/
#include <cstdint> // uint32_t

class Solution
{
public:
  int hammingWeight(uint32_t n)
  {
    int ans = 0;
    while (n != 0)
    {
      ans += n % 2;
      n >>= 1;
    }
    return ans;
  }
};

#include "gtest/gtest.h"

TEST(leetcode191, sampleInputByProblem1)
{
  Solution solution;
  uint32_t in = 0b00000000000000000000000000001011;
  ASSERT_EQ(3, solution.hammingWeight(in));
}

TEST(leetcode191, sampleInputByProblem2)
{
  Solution solution;
  uint32_t in = 0b00000000000000000000000010000000;
  ASSERT_EQ(1, solution.hammingWeight(in));
}

TEST(leetcode191, sampleInputByProblem3)
{
  Solution solution;
  uint32_t in = 0b11111111111111111111111111111101;
  ASSERT_EQ(31, solution.hammingWeight(in));
}