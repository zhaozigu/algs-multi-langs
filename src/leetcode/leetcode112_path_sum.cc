// https://leetcode-cn.com/problems/path-sum/
#include "treenode.hpp"

class Solution
{
public:
  bool hasPathSum(TreeNode *root, int sum)
  {
    if (root == nullptr)
      return false;
    if (root->left == nullptr && root->right == nullptr && sum == root->val)
      return true;
    return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
  }
};

#include "gtest/gtest.h"

/// [5,4,8,11,null,13,4,7,2,null,null,null,1]
TEST(leetcode112, sampleInputByProblem)
{
  Solution solution;
  HeapTree nodes = {
      TNode(5),
      TNode(4),
      TNode(8),
      TNode(11),
      nullptr,
      TNode(13),
      TNode(4),
      TNode(7),
      TNode(2),
      nullptr,
      nullptr,
      nullptr,
      TNode(1)};
  ASSERT_TRUE(solution.hasPathSum(BuildTree(nodes), 22));
}