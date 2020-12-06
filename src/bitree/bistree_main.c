#include <stdio.h>
#include "bistree.h"

int cmp(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

int main()
{
  BisTree bistree;
  bistree_init(&bistree, cmp, NULL);
  printf("size = %d\n", bistree.size);
  int a = 1;
  bistree_insert(&bistree, (void *)&a);
  int *pa = &a;
  printf("lookup: %d\n", bistree_lookup(&bistree, (void **)&pa));
  printf("size = %d\n", bistree.size);
  bistree_remove(&bistree, (void *)&a);
  printf("lookup: %d\n", bistree_lookup(&bistree, (void **)&pa));
  printf("size = %d\n", bistree.size);
  bistree_destroy(&bistree);
}
