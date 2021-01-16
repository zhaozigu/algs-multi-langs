// The API isBadVersion is defined for you.
bool isBadVersion(int version)
{
  bool bad[] = {false, false, false, false, true, true, true};
  return bad[version];
}

class Solution
{
public:
  int firstBadVersion(int n)
  {
    int low = 1, high = n;
    while (low <= high)
    {
      int mid = (high - low) / 2 + low;
      if (isBadVersion(mid))
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    return low;
  }
};

#include "gtest/gtest.h"

TEST(leetcode278, sampleInputByProblem)
{
  Solution solution;
  ASSERT_EQ(4, solution.firstBadVersion(5));
}