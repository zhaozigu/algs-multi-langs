#include <stdio.h>
#include "bitree.h"
#include "traverse.h"

typedef int (*TraverseFunc)(const BiTreeNode *node, List *list);

void sample_test(const BiTree *bitree, TraverseFunc traverse)
{
  List list;
  list_init(&list, NULL);
  traverse(bitree_root(bitree), &list);
  printf("%d -> %d -> %d\n",
         (int)list_data(list_head(&list)),
         (int)list_data(list_next(list_head(&list))),
         (int)list_data(list_next(list_next(list_head(&list)))));
  list_destroy(&list);
}

int main()
{
  BiTree bitree;
  bitree_init(&bitree, NULL);
  printf("size = %d\n", bitree.size);

  // 根
  printf("%d\n", bitree_ins_left(&bitree, NULL, (void *)5));
  // 左
  printf("%d\n", bitree_ins_left(&bitree, bitree_root(&bitree), (void *)3));
  // 右
  printf("%d\n", bitree_ins_right(&bitree, bitree_root(&bitree), (void *)7));

  printf("size = %d\n", bitree.size);

  sample_test(&bitree, preorder);
  sample_test(&bitree, inorder);
  sample_test(&bitree, postorder);
  bitree_destroy(&bitree);
}