// https://leetcode-cn.com/problems/reverse-integer/
#include <string>
using namespace std;

class Solution
{
public:
  int reverse(int x)
  {
    string s = to_string(x);
    if (s[0] == '-')
    {
      std::reverse(s.begin() + 1, s.end());
    }
    else
    {
      std::reverse(s.begin(), s.end());
    }

    long long int temp = stoll(s);
    if (temp > 2147483647 || temp < -2147483648)
    {
      return 0;
    }

    return static_cast<int>(temp);
  }
};

#include "gtest/gtest.h"

TEST(leetcode7, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_EQ(321, solution.reverse(123));
}

TEST(leetcode7, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_EQ(-321, solution.reverse(-123));
}

TEST(leetcode7, sampleInputByProblem3)
{
  Solution solution;
  ASSERT_EQ(21, solution.reverse(120));
}

TEST(leetcode7, sampleInputByProblem4)
{
  Solution solution;
  ASSERT_EQ(0, solution.reverse(0));
}

TEST(leetcode7, BoundaryValueMax)
{
  Solution solution;
  ASSERT_EQ(0, solution.reverse((int)2147483648));
}

TEST(leetcode7, BoundaryValueMin)
{
  Solution solution;
  ASSERT_EQ(0, solution.reverse((int)-2147483648));
}