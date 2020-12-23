// https://leetcode-cn.com/problems/pascals-triangle-ii/
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> v(rowIndex + 1);
        v[0] = 1;
        for (int i = 1; i <= rowIndex; i++)
        {
            v[i] = (long long int)v[i - 1] * (long long int)(rowIndex - i + 1) / i;
        }
        return v;
    }
};

#include "gtest/gtest.h"

TEST(leetcode119, sampleInputByProblem1)
{
    Solution solution;
    vector<int> out = {1, 3, 3, 1};
    ASSERT_EQ(out, solution.getRow(3));
}

TEST(leetcode119, sampleInputByProblem2)
{
    Solution solution;
    vector<int> out = {1};
    ASSERT_EQ(out, solution.getRow(0));
}

TEST(leetcode119, sampleInputByProblem3)
{
    Solution solution;
    vector<int> out = {1, 1};
    ASSERT_EQ(out, solution.getRow(1));
}