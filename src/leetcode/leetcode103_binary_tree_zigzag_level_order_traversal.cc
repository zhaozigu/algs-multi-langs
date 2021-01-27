// https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
#include <vector>
#include <queue>

#include "treenode.hpp"

class Solution
{
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    vector<vector<int>> res;
    queue<TreeNode *> q;
    if (root)
      q.push(root);

    bool lr = true;
    while (!q.empty())
    {
      int size = q.size();
      vector<int> level(size, 0);
      while (size--)
      {
        root = q.front();
        q.pop();
        // 直接插入到对应索引位置
        level[lr ? level.size() - size - 1 : size] = root->val;
        if (root->left)
          q.push(root->left);
        if (root->right)
          q.push(root->right);
      }
      res.push_back(move(level));
      lr = !lr;
    }

    return res;
  }
};

#include "gtest/gtest.h"

TEST(leetcode103, sampleInputByProblem)
{
  Solution solution;
  HeapTree nodes = {TNode(3), TNode(9), TNode(20), nullptr, nullptr, TNode(15), TNode(7)};
  vector<vector<int>> outs = {
      {3},
      {20, 9},
      {15, 7}};
  ASSERT_EQ(outs, solution.zigzagLevelOrder(BuildTree(nodes)));
}