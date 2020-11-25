#pragma once

const int kMaxN = 1005;

class Solve
{
public:
  int GetPopNum(int *b, int n)
  {
    int count = 0;
    for (int i = 1, k = 0; i <= n && count < n; i++, k++)
    {
      // i进a[]栈
      a[k] = i;
      // 若入栈元素a[k]为当前出栈元素b[count]，则a[]直接出栈
      while (a[k] == b[count])
      {
        if (k > 0)
        {
          --k;
        }
        else
        {
          // 0进入栈底a[0]，设栈空标志-1
          a[k] = 0;
          --k;
        }
        // b[count]顺利出栈，分析下一个出栈元素
        ++count;
        // 若a[]栈空，则退出while
        if (k == -1)
          break;
      }
    }

    return count;
  }

private:
  int a[kMaxN];
};