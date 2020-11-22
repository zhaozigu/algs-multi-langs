/** \file

 二叉树遍历的接口定义
*/
#include "bitree.h"
#include "../list/list.h"

/// 前序遍历
int preorder(const BiTreeNode *node, List *list);
/// 中序遍历
int inorder(const BiTreeNode *node, List *list);
/// 后序遍历
int postorder(const BiTreeNode *node, List *list);
