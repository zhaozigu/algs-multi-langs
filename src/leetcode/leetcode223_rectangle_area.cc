// https://leetcode-cn.com/problems/rectangle-area/
#include <algorithm>
using namespace std;

class Solution
{
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
  {
    int maxae = max(A, E);
    int mincg = min(C, G);
    int maxfb = max(F, B);
    int minhd = min(D, H);
    int overlap;
    if (maxae >= mincg || maxfb >= minhd)
      overlap = 0;
    else
      overlap = (mincg - maxae) * (minhd - maxfb);
    return (C - A) * (D - B) - overlap + (G - E) * (H - F);
  }
};

#include "gtest/gtest.h"

TEST(leetcode223, sampleInputByProblem)
{
  Solution solution;
  ASSERT_EQ(45, solution.computeArea(-3, 0, 3, 4, 0, -1, 9, 2));
}