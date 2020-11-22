// http://poj.org/problem?id=1004
#include <cstdio>

// 提交代码记得拷贝代码
#include "poj1004.hpp"

int main()
{
  double temp;
  Solve solve;
  for (int i = 0; i < 12; i++)
  {
    scanf("%lf", &temp);
    solve.Add(temp);
  }

  printf("$%.2f\n", solve.GetAvg());
  return 0;
}