#pragma once
#include <algorithm>
using std::max;
using std::min;

class Solve
{
public:
  int MaxCycleLength(int i, int j)
  {
    int max_num = 1;
    // 枚举范围内所有的整数
    for (int n = min(i, j); n <= max(i, j); n++)
    {
      int i, m;
      for (i = 1, m = n; m > 1; i++)
      {
        if (m % 2 == 0)
        {
          m /= 2;
        }
        else
        {
          m = 3 * m + 1;
        }
      }
      if (i > max_num)
      {
        max_num = i;
      }
    }
    return max_num;
  }
};