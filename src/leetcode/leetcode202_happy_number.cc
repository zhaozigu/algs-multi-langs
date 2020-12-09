// https://leetcode-cn.com/problems/happy-number/
class Solution
{
public:
  bool isHappy(int n)
  {
    int cnt = 0;
    while (n != 1)
    {
      cnt++;
      int temp = 0;
      while (n)
      {
        temp += (n % 10) * (n % 10);
        n /= 10;
      }
      n = temp;
      if (cnt == 10)
      {
        return false;
      }
    }
    return true;
  }
};

#include "gtest/gtest.h"

TEST(leetcode202, sampleInputByProblem)
{
  Solution solution;
  ASSERT_TRUE(solution.isHappy(19));
}
