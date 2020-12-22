// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int inf = numeric_limits<int>::max();
    int minprice = inf,
        maxprofit = 0;
    for (int price : prices)
    {
      maxprofit = max(maxprofit, price - minprice);
      minprice = min(price, minprice);
    }
    return maxprofit;
  }
};

#include "gtest/gtest.h"

TEST(leetcode121, sampleInputByProblem1)
{
  Solution solution;
  vector<int> ins = {7, 1, 5, 3, 6, 4};
  ASSERT_EQ(5, solution.maxProfit(ins));
}

TEST(leetcode121, sampleInputByProblem2)
{
  Solution solution;
  vector<int> ins = {7, 6, 4, 3, 1};
  ASSERT_EQ(0, solution.maxProfit(ins));
}