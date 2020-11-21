#include <stdio.h>
#include <math.h>
#include "sort.h"

static int compare_int(const void *int1, const void *int2)
{
  if (*(const int *)int1 > *(const int *)int2)
  {
    return 1;
  }
  else if (*(const int *)int1 < *(const int *)int2)
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  int a[] = {1, 2, 18, 21, 4};
  qksort((void *)a, 5, sizeof(int), 0, 4, compare_int);

  for (int i = 0; i < 5; i++)
  {
    printf("%d ", a[i]);
  }
}