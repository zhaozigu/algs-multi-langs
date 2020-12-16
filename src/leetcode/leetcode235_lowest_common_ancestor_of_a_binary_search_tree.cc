// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
#include "treenode.hpp"

class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (root == nullptr || p == nullptr || q == nullptr)
    {
      return nullptr;
    }
    if ((p->val >= root->val && q->val <= root->val) || (p->val <= root->val && q->val >= root->val))
    {
      return root;
    }
    if (p->val > root->val && q->val > root->val)
    {
      return lowestCommonAncestor(root->right, p, q);
    }
    if (p->val < root->val && q->val < root->val)
    {
      return lowestCommonAncestor(root->left, p, q);
    }
    return nullptr;
  }
};

#include "gtest/gtest.h"

TEST(leetcode235, sampleInputByProblem1)
{
  Solution solution;
  HeapTree nodes = {
      TNode(6), TNode(2), TNode(8),
      TNode(0), TNode(4), TNode(7),
      TNode(9), nullptr, nullptr,
      TNode(3), TNode(5)};
  ASSERT_EQ(6, solution.lowestCommonAncestor(BuildTree(nodes), &*nodes[1], &*nodes[2])->val);
}

TEST(leetcode235, sampleInputByProblem2)
{
  Solution solution;
  HeapTree nodes = {
      TNode(6), TNode(2), TNode(8),
      TNode(0), TNode(4), TNode(7),
      TNode(9), nullptr, nullptr,
      TNode(3), TNode(5)};
  ASSERT_EQ(2, solution.lowestCommonAncestor(BuildTree(nodes), &*nodes[1], &*nodes[4])->val);
}

TEST(leetcode235, sampleInputByProblem3)
{
  Solution solution;
  HeapTree nodes = {TNode(2), TNode(1)};
  ASSERT_EQ(2, solution.lowestCommonAncestor(BuildTree(nodes), &*nodes[0], &*nodes[1])->val);
}
