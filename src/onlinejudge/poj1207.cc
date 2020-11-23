// http://poj.org/problem?id=1207
#include <cstdio>

#include "poj1207.hpp"
using namespace std;

int i, j;

int main()
{
  Solve solve;
  while (scanf("%d %d", &i, &j) == 2)
  {
    printf("%d %d %d\n", i, j, solve.MaxCycleLength(i, j));
  }
  return 0;
}