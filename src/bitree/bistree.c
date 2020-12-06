#include <stdlib.h>
#include <string.h>
#include "bistree.h"

static void destroy_right(BisTree *tree, BiTreeNode *node);
static void destroy_left(BisTree *tree, BiTreeNode *node);

// 左旋
static void rotate_left(BiTreeNode **node)
{
  BiTreeNode *left = bitree_left(*node);
  if (((AvlNode *)bitree_data(left))->factor == AVL_LFT_HEAVY)
  {
    // LL 旋转
    bitree_left(*node) = bitree_right(left);
    bitree_right(left) = *node;
    ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
    ((AvlNode *)bitree_data(left))->factor = AVL_BALANCED;
    *node = left;
  }
  else
  {
    // LR 旋转
    BiTreeNode *grandchild = bitree_right(left);
    bitree_right(left) = bitree_left(grandchild);
    bitree_left(grandchild) = left;
    bitree_left(*node) = bitree_right(grandchild);
    bitree_right(grandchild) = *node;

    switch (((AvlNode *)bitree_data(grandchild))->factor)
    {
    case AVL_LFT_HEAVY:
    {
      ((AvlNode *)bitree_data(*node))->factor = AVL_RGT_HEAVY;
      ((AvlNode *)bitree_data(left))->factor = AVL_BALANCED;
      break;
    }
    case AVL_BALANCED:
    {
      ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
      ((AvlNode *)bitree_data(left))->factor = AVL_BALANCED;
      break;
    }
    case AVL_RGT_HEAVY:
    {
      ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
      ((AvlNode *)bitree_data(left))->factor = AVL_LFT_HEAVY;
      break;
    }
    }

    ((AvlNode *)bitree_data(grandchild))->factor = AVL_BALANCED;
    *node = grandchild;
  }

  return;
}

// 右旋
static void rotate_right(BiTreeNode **node)
{
  BiTreeNode *right = bitree_right(*node);
  if (((AvlNode *)bitree_data(right))->factor == AVL_RGT_HEAVY)
  {
    // RR 旋转
    bitree_right(*node) = bitree_left(right);
    bitree_left(right) = *node;
    ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
    ((AvlNode *)bitree_data(right))->factor = AVL_BALANCED;
    *node = right;
  }
  else
  {
    // RL 旋转
    BiTreeNode *grandchild = bitree_left(right);
    bitree_left(right) = bitree_right(grandchild);
    bitree_right(grandchild) = right;
    bitree_right(*node) = bitree_left(grandchild);
    bitree_left(grandchild) = *node;

    switch (((AvlNode *)bitree_data(grandchild))->factor)
    {
    case AVL_LFT_HEAVY:
    {
      ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
      ((AvlNode *)bitree_data(right))->factor = AVL_RGT_HEAVY;
      break;
    }
    case AVL_BALANCED:
    {
      ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
      ((AvlNode *)bitree_data(right))->factor = AVL_BALANCED;
      break;
    }
    case AVL_RGT_HEAVY:
    {
      ((AvlNode *)bitree_data(*node))->factor = AVL_LFT_HEAVY;
      ((AvlNode *)bitree_data(right))->factor = AVL_BALANCED;
      break;
    }
    }
    ((AvlNode *)bitree_data(grandchild))->factor = AVL_BALANCED;
    *node = grandchild;
  }
}

// 销毁左子树
static void destroy_left(BisTree *tree, BiTreeNode *node)
{
  BiTreeNode **position;

  if (bitree_size(tree) == 0)
  {
    return;
  }

  if (node == NULL)
  {
    position = &tree->root;
  }
  else
  {
    position = &node->left;
  }

  if (*position != NULL)
  {
    destroy_left(tree, *position);
    destroy_right(tree, *position);

    if (tree->destroy != NULL)
    {
      tree->destroy(((AvlNode *)(*position)->data)->data);
    }

    free((*position)->data);
    free(*position);
    *position = NULL;

    --tree->size;
  }
  return;
}

// 销毁右子树
static void destroy_right(BisTree *tree, BiTreeNode *node)
{
  BiTreeNode **position;

  if (bitree_size(tree) == 0)
  {
    return;
  }

  if (node == NULL)
  {
    position = &tree->root;
  }
  else
  {
    position = &node->right;
  }

  if (*position != NULL)
  {
    destroy_left(tree, *position);
    destroy_right(tree, *position);

    if (tree->destroy != NULL)
    {
      tree->destroy(((AvlNode *)(*position)->data)->data);
    }

    free((*position)->data);
    free(*position);
    *position = NULL;

    --tree->size;
  }
  return;
}

static int insert(BisTree *tree, BiTreeNode **node, const void *data, int *balanced)
{
  AvlNode *avl_data;
  int cmpval, retval;

  if (bitree_is_eob(*node))
  {
    // 插入到空树
    if ((avl_data = (AvlNode *)malloc(sizeof(AvlNode))) == NULL)
    {
      return -1;
    }

    avl_data->factor = AVL_BALANCED;
    avl_data->hidden = 0;
    avl_data->data = (void *)data;

    return bitree_ins_left(tree, *node, avl_data);
  }
  else
  {
    cmpval = tree->compare(data, ((AvlNode *)bitree_data(*node))->data);

    if (cmpval < 0)
    {
      if (bitree_is_eob(bitree_left(*node)))
      {
        if ((avl_data = (AvlNode *)malloc(sizeof(AvlNode))) == NULL)
        {
          return -1;
        }

        avl_data->factor = AVL_BALANCED;
        avl_data->hidden = 0;
        avl_data->data = (void *)data;

        if (bitree_ins_left(tree, *node, avl_data) != 0)
        {
          return -1;
        }

        *balanced = 0;
      }
      else
      {
        if ((retval = insert(tree, &bitree_left(*node), data, balanced)) != 0)
        {
          return retval;
        }
      }

      // 确保树保持平衡
      if (!(*balanced))
      {
        switch (((AvlNode *)bitree_data(*node))->factor)
        {
        case AVL_LFT_HEAVY:
        {
          rotate_left(node);
          *balanced = 1;
          break;
        }
        case AVL_BALANCED:
        {
          ((AvlNode *)bitree_data(*node))->factor = AVL_LFT_HEAVY;
          break;
        }
        case AVL_RGT_HEAVY:
        {
          ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
          *balanced = 1;
          break;
        }
        }
      }
    }
    else if (cmpval > 0)
    {
      if (bitree_is_eob(bitree_right(*node)))
      {
        if ((avl_data = (AvlNode *)malloc(sizeof(AvlNode))) == NULL)
        {
          return -1;
        }

        avl_data->factor = AVL_BALANCED;
        avl_data->hidden = 0;
        avl_data->data = (void *)data;

        if (bitree_ins_right(tree, *node, avl_data) != 0)
        {
          return -1;
        }

        *balanced = 0;
      }
      else
      {
        if ((retval = insert(tree, &bitree_right(*node), data, balanced)) != 0)
        {
          return retval;
        }
      }
      // 确保树保持平衡
      if (!(*balanced))
      {
        switch (((AvlNode *)bitree_data(*node))->factor)
        {
        case AVL_LFT_HEAVY:
        {
          ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
          *balanced = 1;
          break;
        }
        case AVL_BALANCED:
        {
          ((AvlNode *)bitree_data(*node))->factor = AVL_RGT_HEAVY;
          break;
        }
        case AVL_RGT_HEAVY:
        {
          rotate_right(node);
          *balanced = 1;
          break;
        }
        }
      }
    }
    else
    {
      if (!((AvlNode *)bitree_data(*node))->hidden)
      {
        // 已经在树中了，而且没有被隐藏
        return 1;
      }
      else
      {
        // 插入新数据
        if (tree->destroy != NULL)
        {
          // 已经被取代了
          tree->destroy(((AvlNode *)bitree_data(*node))->data);
        }
        ((AvlNode *)bitree_data(*node))->data = (void *)data;
        ((AvlNode *)bitree_data(*node))->hidden = 0;
        // 没有改变结构，不需要重新平衡
        *balanced = 1;
      }
    }
  }
  return 0;
}

static int hide(BisTree *tree, BiTreeNode *node, const void *data)
{
  if (bitree_is_eob(node))
  {
    return -1;
  }

  int cmpval, retval;
  cmpval = tree->compare(data, ((AvlNode *)bitree_data(node))->data);
  if (cmpval < 0)
  {
    retval = hide(tree, bitree_left(node), data);
  }
  else if (cmpval > 0)
  {
    retval = hide(tree, bitree_right(node), data);
  }
  else
  {
    // 标记为 hidden
    ((AvlNode *)bitree_data(node))->hidden = 1;
    retval = 0;
  }

  return retval;
}

static int lookup(BisTree *tree, BiTreeNode *node, void **data)
{
  if (bitree_is_eob(node))
  {
    return -1;
  }

  int cmpval, retval;
  cmpval = tree->compare(*data, ((AvlNode *)bitree_data(node))->data);
  if (cmpval < 0)
  {
    retval = lookup(tree, bitree_left(node), data);
  }
  else if (cmpval > 0)
  {
    retval = lookup(tree, bitree_right(node), data);
  }
  else
  {
    if (!((AvlNode *)bitree_data(node))->hidden)
    {
      *data = ((AvlNode *)bitree_data(node))->data;
      retval = 0;
    }
    else
    {
      return -1;
    }
  }

  return retval;
}

void bistree_init(BisTree *tree, int (*compare)(const void *key1, const void *key2), void (*destroy)(void *data))
{
  bitree_init(tree, destroy);
  tree->compare = compare;

  return;
}

void bistree_destroy(BisTree *tree)
{
  destroy_left(tree, NULL);
  memset(tree, 0, sizeof(BisTree));
  return;
}

int bistree_insert(BisTree *tree, const void *data)
{
  int balanced = 0;
  return insert(tree, &bitree_root(tree), data, &balanced);
}

int bistree_remove(BisTree *tree, const void *data)
{
  // 惰性删除
  return hide(tree, bitree_root(tree), data);
}

int bistree_lookup(BisTree *tree, void **data)
{
  return lookup(tree, bitree_root(tree), data);
}
