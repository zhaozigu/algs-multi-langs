struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
  TreeNode node1(2);
  TreeNode node2(3);
  TreeNode tree1(1, &node1, &node2);
  TreeNode tree2(1, &node1, &node2);
  EXPECT_EQ(true, solution.isSameTree(&tree1, &tree2));
}

TEST(leetcode100, sampleInputByProblem2)
{
  Solution solution;
  TreeNode node(2);
  TreeNode tree1(1, &node, nullptr); // [1,2]
  TreeNode tree2(1, nullptr, &node); // [1, null, 2]
  EXPECT_EQ(false, solution.isSameTree(&tree1, &tree2));
}

TEST(leetcode100, sampleInputByProblem3)
{
  Solution solution;
  TreeNode node1(1);
  TreeNode node2(2);
  TreeNode tree1(1, &node1, &node2);
  TreeNode tree2(1, &node2, &node1);
  EXPECT_EQ(false, solution.isSameTree(&tree1, &tree2));
}