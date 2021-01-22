// https://leetcode-cn.com/problems/binary-tree-right-side-view/
#include <vector>
#include <queue>

#include "treenode.hpp"

using namespace std;

class Solution
{
public:
  vector<int> rightSideView(TreeNode *root)
  {
    vector<int> res;
    if (!root)
      return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      int size = q.size();
      res.push_back(q.front()->val);
      while (size--)
      {
        TreeNode *temp = q.front();
        q.pop();
        if (temp->right)
          q.push(temp->right);
        if (temp->left)
          q.push(temp->left);
      }
    }
    return res;
  }
};

#include "gtest/gtest.h"

TEST(leetcode199, smapleInputByProblem)
{
  HeapTree nodes = {
      TNode(1),
      TNode(2),
      TNode(3),
      nullptr,
      TNode(5),
      nullptr,
      TNode(4),
  };
  Solution solution;
  ASSERT_EQ(vector<int>({1, 3, 4}),
            solution.rightSideView(BuildTree(nodes)));
}