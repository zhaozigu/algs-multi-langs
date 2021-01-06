// https://leetcode-cn.com/problems/merge-sorted-array/
#include <vector>
using namespace std;

class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    int p1 = m - 1, p2 = n - 1, p3 = m + n - 1;
    while (p2 >= 0)
    {
      if (p1 >= 0 && nums1[p1] > nums2[p2])
      {
        nums1[p3--] = nums1[p1--];
      }
      else
      {
        nums1[p3--] = nums2[p2--];
      }
    }
  }
};

#include "gtest/gtest.h"

TEST(leetcode88, sampleInputByProblem1)
{
  //nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  vector<int> outs = {1, 2, 2, 3, 5, 6};
  Solution solution;
  solution.merge(nums1, 3, nums2, 3);
  ASSERT_EQ(outs, nums1);
}

TEST(leetcode88, sampleInputByProblem2)
{
  vector<int> nums1 = {1};
  vector<int> nums2 = {};
  vector<int> outs = {1};
  Solution solution;
  solution.merge(nums1, 1, nums2, 0);
  ASSERT_EQ(outs, nums1);
}