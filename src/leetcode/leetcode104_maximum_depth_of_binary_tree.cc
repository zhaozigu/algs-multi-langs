// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
#include <algorithm>
using namespace std;
#include "treenode.hpp"

class Solution
{
public:
  int maxDepth(TreeNode *root)
  {
    return root == nullptr ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

#include "gtest/gtest.h"

TEST(leetcode104, sampleInputByProblem)
{
  Solution solution;
  HeapTree nodes = {TNode(3), TNode(9), TNode(20), nullptr, nullptr, TNode(15), TNode(7)};
  ASSERT_EQ(3, solution.maxDepth(BuildTree(nodes)));
}
