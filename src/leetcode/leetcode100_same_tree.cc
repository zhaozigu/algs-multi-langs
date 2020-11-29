// https://leetcode-cn.com/problems/same-tree/
#include "treenode.hpp"

class Solution
{
public:
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    if (p != nullptr && q != nullptr)
      return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    return p == nullptr && q == nullptr;
  }
};

#include "gtest/gtest.h"

TEST(leetcode100, sampleInputByProblem1)
{
  Solution solution;
  HeapTree heaptree1 = {TNode(1), TNode(2), TNode(3)};
  HeapTree heaptree2 = {TNode(1), TNode(2), TNode(3)};
  TreeNode *tree1 = BuildTree(heaptree1);
  TreeNode *tree2 = BuildTree(heaptree2);
  ASSERT_EQ(true, solution.isSameTree(tree1, tree2));
}

TEST(leetcode100, sampleInputByProblem2)
{
  Solution solution;
  HeapTree heaptree1 = {TNode(1), TNode(2)};
  HeapTree heaptree2 = {TNode(1), nullptr, TNode(2)};
  TreeNode *tree1 = BuildTree(heaptree1);
  TreeNode *tree2 = BuildTree(heaptree2);
  ASSERT_EQ(false, solution.isSameTree(tree1, tree2));
}

TEST(leetcode100, sampleInputByProblem3)
{
  Solution solution;
  HeapTree heaptree1 = {TNode(1), TNode(2), TNode(1)};
  HeapTree heaptree2 = {TNode(1), TNode(1), TNode(2)};
  TreeNode *tree1 = BuildTree(heaptree1);
  TreeNode *tree2 = BuildTree(heaptree2);
  ASSERT_EQ(false, solution.isSameTree(tree1, tree2));
}
