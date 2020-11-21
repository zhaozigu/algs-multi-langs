#ifndef __SORT_H__
#define __SORT_H__

/// 快速排序
int qksort(void *data, int size, int esize, int i, int k, int (*compare)(const void *key1, const void *key2));

#endif