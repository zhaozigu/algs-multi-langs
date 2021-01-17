// https://leetcode-cn.com/problems/unique-binary-search-trees/
#include <vector>
using namespace std;

class Solution
{
public:
  int numTrees(int n)
  {
    vector<int> v(n + 1);
    v[0] = 1;
    for (int i = 1; i <= n; i++)
    {
      v[i] = 0;
      if (i <= 2)
      {
        v[i] = i;
      }
      else
      {
        for (int j = 1; j <= i; j++)
        {
          v[i] += v[j - 1] * v[i - j];
        }
      }
    }
    return v[n];
  }
};

#include "gtest/gtest.h"

TEST(leetcode96, sampleInputByProblem)
{
  Solution solution;
  ASSERT_EQ(5, solution.numTrees(3));
}