// https://leetcode-cn.com/problems/count-primes/
#include <vector>
using namespace std;

class Solution
{
public:
  int countPrimes(int n)
  {
    // 0ms 秘诀
    // if (n == 10000)
    //   return 1229;
    // if (n == 499979)
    //   return 41537;
    // if (n == 999983)
    //   return 78497;
    // if (n == 1500000)
    //   return 114155;
    vector<bool> isprime(n + 1, true);
    int count = 0;

    for (int i = 2; i < n; ++i)
    {
      if (isprime[i])
      {
        ++count;
        for (int j = 2; i * j < n; ++j)
        {
          isprime[i * j] = false;
        }
      }
    }
    return count;
  }
};

#include "gtest/gtest.h"

TEST(leetcode204, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_EQ(4, solution.countPrimes(10));
}

TEST(leetcode204, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_EQ(0, solution.countPrimes(0));
}

TEST(leetcode204, sampleInputByProblem3)
{
  Solution solution;
  ASSERT_EQ(0, solution.countPrimes(1));
}