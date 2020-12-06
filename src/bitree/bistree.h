/** \file

 二叉搜索树的接口定义
*/
#ifndef __BISTREE_H__
#define __BISTREE_H__

#include "bitree.h"

/* 定义平衡因子 */
#define AVL_LFT_HEAVY 1
#define AVL_BALANCED 0
#define AVL_RGT_HEAVY -1

/// AVL 树结点
typedef struct AvlNode_
{
  void *data;
  int hidden;
  int factor;
} AvlNode;

/// 使用二叉树实现二叉搜索树
typedef BiTree BisTree;

/** 初始化由 tree 指定的二叉搜索树。
 * \param compare 指定一个用户定义的比较函数
 * \param destroy 提供释放内存的析构函数
*/
void bistree_init(BisTree *tree,
                  int (*compare)(const void *key1, const void *key2),
                  void (*destroy)(void *data));

/** 销毁由参数 tree 指定的二叉树
 * \param tree 指定的二叉树
*/
void bistree_destroy(BisTree *tree);
/** 将结点插入到由 tree 所指定的二叉搜索树中
 * \param tree 指定的二叉树
 * \param data 插入的数据
 * \return 0==插入成功，1==已经存在，否则返回 -1
*/
int bistree_insert(BisTree *tree, const void *data);
/** 移除 tree 所指定的二叉树中同参数 data 相同的结点
 * \param tree 指定的二叉树
 * \param data 需要删除的数据
 * \return 0==移除成功，否则返回 -1
*/
int bistree_remove(BisTree *tree, const void *data);
/** 查找 tree 所指定的二叉树中同参数 data 相同的结点
 * \param tree 指定的二叉树
 * \param data 需要查找的数据
 * \return 0==成功查到，否则返回 -1
*/
int bistree_lookup(BisTree *tree, void **data);
/// 二叉搜索树中的结点个数
#define bistree_size(tree) ((tree)->size)
#endif