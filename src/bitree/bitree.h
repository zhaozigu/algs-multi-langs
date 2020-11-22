/** \file

 二叉树的接口定义*/

#ifndef __BITREE_H__
#define __BITREE_H__

#include <stdlib.h>

/// 二叉树节点结构
typedef struct BiTreeNode_
{
  void *data;
  struct BiTreeNode_ *left;
  struct BiTreeNode_ *right;
} BiTreeNode;

/// 二叉树结构
typedef struct BiTree_
{
  int size;
  int (*compare)(const void *key1, const void *key2);
  void (*destroy)(void *data);
  BiTreeNode *root;
} BiTree;

/** 初始化由参数 tree 所指定的二叉树。该函数必须在其他操作之前被调用。
 \param tree 二叉树结构
 \param destroy 提供释放动态分配数据空间的方法。如果不需要释放数据，应该设置为 NULL
*/
void bitree_init(BiTree *tree, void (*destroy)(void *data));
/** 销毁由参数 tree 指定的的二叉树。执行之后不能再执行任何其他操作，除非重新使用 bitree_init。
 \param tree 二叉树结构
 */
void bitree_destroy(BiTree *tree);
/** 在 tree 所指定的二叉树中插入一个结点，使其成为 node 所指定结点的左子结点。
 - 如果 node 已经有了左子结点，则返回 -1
 - 如果 node 为 NULL，则新结点作为根结点插入。插入根结点必须保证树为空，否则返回 -1
 \warning 只要结点还在二叉树中，data 所引用的内存就必须有效。
 \param tree 二叉树结构
 \param node 父结点
 \param data 结点数据
 \return 0==OK, -1==failure
*/
int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data);
/** 在 tree 所指定的二叉树中插入一个结点，使其成为 node 所指定结点的右子结点。
 - 如果 node 已经有了右子结点，则返回 -1
 - 如果 node 为 NULL，则新结点作为根结点插入。插入根结点必须保证树为空，否则返回 -1
 \warning 只要结点还在二叉树中，data 所引用的内存就必须有效。
 \param tree 二叉树结构
 \param node 父结点
 \param data 结点数据
 \return 0==OK, -1==failure
*/
int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data);
/** 移除由 tree 指定的二叉树中 node 结点的左子树。如果 node 为 NULL，则移除树中的所有结点。
 * \param tree 二叉树结构
 * \param node 父结点
 */
void bitree_rem_left(BiTree *tree, BiTreeNode *node);
/** 移除由 tree 指定的二叉树中 node 结点的油子树。如果 node 为 NULL，则移除树中的所有结点。
 * \param tree 二叉树结构
 * \param node 父结点
 */
void bitree_rem_right(BiTree *tree, BiTreeNode *node);
/** 将 left 和 right 所指定的两棵二叉树合并为单棵树。
 \param merge 合并结点
 \param left 待合并的左子树
 \param right 待合并的右子树
 \param data 结点数据
 \return 0==OK, -1==failure
*/
int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data);

/// 返回树中结点个数
#define bitree_size(tree) ((tree)->size)
/// 返回 tree 指定的二叉树的根结点
#define bitree_root(tree) ((tree)->root)
/// 如果 node 标识的是树的分支结束，返回1，否则返回0
#define bitree_is_eob(node) ((node) == NULL)
/// 如果是叶子结点，返回1，否则返回0
#define bitree_is_leaf(node) ((node)->left == NULL && (node)->right == NULL)
/// 返回存储在结点中的数据
#define bitree_data(node) ((node)->data)
/// 返回指定结点的左子结点
#define bitree_left(node) ((node)->left)
/// 返回指定结点的右子结点
#define bitree_right(node) ((node)->right)
#endif