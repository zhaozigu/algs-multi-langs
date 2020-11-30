#pragma once
/// Leetcode 通用的树结点定义
#include <vector>
#include <queue>
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
using std::queue;
using std::shared_ptr;
using std::vector;

using PtrNode = shared_ptr<TreeNode>;
using HeapTree = vector<PtrNode>;
#define TNode(x) (make_shared<TreeNode>(x))

/// 将数组表达的二叉树结构转换成链式表达的二叉树结构
TreeNode *BuildTree(HeapTree &nodes)
{
  if (nodes.size() == 0)
  {
    return nullptr;
  }

  int index = 0;
  queue<PtrNode> queue_nodes;
  queue_nodes.push(nodes[0]);

  while (!queue_nodes.empty())
  {
    TreeNode &cur = *queue_nodes.front();
    queue_nodes.pop();
    if (index + 1 < nodes.size() && nodes[++index] != nullptr)
    {
      queue_nodes.push(nodes[index]);
      cur.left = &(*nodes[index]);
    }

    if (index + 1 < nodes.size() && nodes[++index] != nullptr)
    {
      queue_nodes.push(nodes[index]);
      cur.right = &(*nodes[index]);
    }
  }

  return &(*nodes[0]);
}
