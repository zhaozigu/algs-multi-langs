// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii
#include <vector>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int ans = 0;
    for (int i = 1; i < prices.size(); i++)
    {
      if (prices[i] > prices[i - 1])
        ans += prices[i] - prices[i - 1];
    }
    return ans;
  }
};

#include "gtest/gtest.h"

TEST(leetcode122, sampleInputByProblem1)
{
  Solution solution;
  vector<int> ins = {7, 1, 5, 3, 6, 4};
  ASSERT_EQ(7, solution.maxProfit(ins));
}

TEST(leetcode122, sampleInputByProblem2)
{
  Solution solution;
  vector<int> ins = {1, 2, 3, 4, 5};
  ASSERT_EQ(4, solution.maxProfit(ins));
}

TEST(leetcode122, sampleInputByProblem3)
{
  Solution solution;
  vector<int> ins = {7, 6, 4, 3, 1};
  ASSERT_EQ(0, solution.maxProfit(ins));
}