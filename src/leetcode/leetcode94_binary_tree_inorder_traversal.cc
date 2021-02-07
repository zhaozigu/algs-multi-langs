// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
#include <vector>

#include "treenode.hpp"

using namespace std;

class Solution
{
public:
  vector<int> result;

  vector<int> inorderTraversal(TreeNode *root)
  {
    dfs(root);
    return result;
  }

  void dfs(TreeNode *root)
  {
    if (root == nullptr)
      return;
    dfs(root->left);
    result.push_back(root->val);
    dfs(root->right);
  }
};

#include "gtest/gtest.h"

TEST(leetcode94, sampleInputByProblem1)
{
  Solution solution;
  HeapTree root = {TNode(1), nullptr, TNode(2), TNode(3)};
  vector<int> outs = {1, 3, 2};
  ASSERT_EQ(outs, solution.inorderTraversal(BuildTree(root)));
}

TEST(leetcode94, sampleInputByProblem2)
{
  Solution solution;
  HeapTree root = {};
  vector<int> outs = {};
  ASSERT_EQ(outs, solution.inorderTraversal(BuildTree(root)));
}

TEST(leetcode94, sampleInputByProblem3)
{
  Solution solution;
  HeapTree root = {TNode(1)};
  vector<int> outs = {1};
  ASSERT_EQ(outs, solution.inorderTraversal(BuildTree(root)));
}