#pragma once
/// Leetcode 通用的树结点定义
#include <vector>
#include <memory>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using std::make_shared;
using std::shared_ptr;
using std::vector;

using HeapTree = vector<shared_ptr<TreeNode>>;
#define TNode(x) (make_shared<TreeNode>(x))

/// 将数组表达的二叉树结构转换成链式表达的二叉树结构
TreeNode *BuildTree(HeapTree &nodes)
{
  for (int i = 0; 2 * i + 2 < nodes.size(); i++)
  {
    TreeNode &cur = *nodes[i];
    cur.left = &(*nodes[2 * i + 1]);
    cur.right = &(*nodes[2 * i + 2]);
  }

  return &(*nodes[0]);
}
