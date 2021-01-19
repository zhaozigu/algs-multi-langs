// https://leetcode-cn.com/problems/gas-station/
#include <vector>
using namespace std;

class Solution
{
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
  {
    if (gas.empty())
      return -1;
    int total = 0, temp = 0, index = 0;
    for (int i = 0; i < gas.size(); i++)
    {
      total += gas[i] - cost[i];
      if (temp >= 0)
      {
        temp += gas[i] - cost[i];
      }
      else
      {
        temp = gas[i] - cost[i];
        index = i;
      }
    }
    return total >= 0 ? index : -1;
  }
};

#include "gtest/gtest.h"

TEST(leetcode134, sampleInputByProblem1)
{
  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};
  Solution solution;
  ASSERT_EQ(3, solution.canCompleteCircuit(gas, cost));
}

TEST(leetcode134, sampleInputByProblem2)
{
  vector<int> gas = {2, 3, 4};
  vector<int> cost = {3, 4, 3};
  Solution solution;
  ASSERT_EQ(-1, solution.canCompleteCircuit(gas, cost));
}