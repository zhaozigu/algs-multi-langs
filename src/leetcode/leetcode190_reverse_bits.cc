// https://leetcode-cn.com/problems/reverse-bits/
#include <cstdint>

class Solution
{
public:
  uint32_t reverseBits(uint32_t n)
  {
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++)
    {
      ans <<= 1;
      ans += n & 1;
      n >>= 1;
    }
    return ans;
  }
};

#include "gtest/gtest.h"

TEST(leetcode190, sampleInputByProblem1)
{
  Solution solution;
  // out: 964176192
  ASSERT_EQ(0b00111001011110000010100101000000, solution.reverseBits(0b00000010100101000001111010011100));
}

TEST(leetcode190, sampleInputByProblem2)
{
  Solution solution;
  // out: 3221225471
  ASSERT_EQ(0b10111111111111111111111111111111, solution.reverseBits(0b11111111111111111111111111111101));
}