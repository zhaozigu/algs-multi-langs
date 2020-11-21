#include <stdio.h>
#include "bitree.h"

int main()
{
  BiTree bitree;
  bitree_init(&bitree, NULL);
  printf("size = %d\n", bitree.size);

  printf("%d\n", bitree_ins_left(&bitree, NULL, (void *)5));
  printf("%d\n", bitree_ins_left(&bitree, bitree_root(&bitree), (void *)5));

  printf("size = %d\n", bitree.size);
  bitree_destroy(&bitree);
}