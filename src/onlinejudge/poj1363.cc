// http://poj.org/problem?id=1363
#include <cstdio>

#include "poj1363.hpp"

// 设a[0..n-1]存储入栈序列[1..n]
// 栈顶指针k
// b[0..n-1]存储待判断的出栈序列，栈顶指针为j
int b[kMaxN];
int main()
{
  Solve solve;
  int n;
  // 反复输入序列长度n，直至输入0(程序结束标志)为止
  while (scanf("%d", &n), n)
  {
    // 反复输入b[0]，直至输入0(长度为n的序列结束标志)为止
    while (scanf("%d", &b[0]), b[0])
    {
      for (int j = 1; j < n; j++)
        scanf("%d", &b[j]);

      if (solve.GetPopNum(b, n) == n)
        printf("Yes\n");
      else
        printf("No\n");
    }
    printf("\n");
  }
  return 0;
}