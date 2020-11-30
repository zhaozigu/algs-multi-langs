// https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
#include <algorithm>
using namespace std;
#include "treenode.hpp"

class Solution
{
public:
  int minDepth(TreeNode *root)
  {
    if (root == nullptr)
    {
      return 0;
    }
    if (root->left && root->right)
    {
      return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    return 1 + minDepth(root->left) + minDepth(root->right);
  }
};

#include "gtest/gtest.h"

TEST(leetcode111, sampleInputByProblem)
{
  Solution solution;
  HeapTree nodes = {TNode(3), TNode(9), TNode(20), nullptr, nullptr, TNode(15), TNode(7)};
  ASSERT_EQ(2, solution.minDepth(BuildTree(nodes)));
}

/// [2,null,3,null,4,null,5,null,6]
TEST(leetcode111, sampleInputByProblem2)
{
  Solution solution;
  HeapTree nodes = {TNode(2), nullptr, TNode(3), nullptr, TNode(4), nullptr, TNode(5), nullptr, TNode(6)};
  ASSERT_EQ(5, solution.minDepth(BuildTree(nodes)));
}
