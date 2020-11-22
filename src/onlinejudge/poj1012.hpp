#pragma once

class Solve
{
public:
  int Survivor(int k)
  {
    int m = 1;          // 最小间隔
    int n = 2 * k;      // 总人数
    int flag[14] = {0}; // 被杀者编号

    for (int i = 1; i <= k; i++)
    {
      flag[i] = (flag[i - 1] + m - 1) % (n - i + 1);
      // 好人先被杀
      if (flag[i] < k)
      {
        m++;
        i = 0;
      }
    }

    return m;
  }
};
