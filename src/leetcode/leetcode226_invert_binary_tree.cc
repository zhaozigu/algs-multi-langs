// https://leetcode-cn.com/problems/Invert-Binary-Tree/
#include <algorithm>
using namespace std;
#include "treenode.hpp"

class Solution
{
public:
  TreeNode *invertTree(TreeNode *root)
  {
    if (root == nullptr)
    {
      return nullptr;
    }
    TreeNode *right_tree = root->right;
    root->right = invertTree(root->left);
    root->left = invertTree(right_tree);
    return root;
  }
};

#include "gtest/gtest.h"

TEST(leetcode226, sampleInputByProblem)
{
  Solution solution;
  HeapTree in_nodes = {TNode(4), TNode(2), TNode(7), TNode(1), TNode(3), TNode(6), TNode(9)};
  HeapTree expect_nodes = {
      TNode(4), TNode(7), TNode(2),
      TNode(9), TNode(6), TNode(3), TNode(9)};

  ASSERT_EQ(7, solution.invertTree(BuildTree(in_nodes))->left->val);
  ASSERT_EQ(2, solution.invertTree(BuildTree(in_nodes))->right->val);

  ASSERT_EQ(6, solution.invertTree(BuildTree(in_nodes))->left->right->val);
  ASSERT_EQ(3, solution.invertTree(BuildTree(in_nodes))->right->left->val);
}
