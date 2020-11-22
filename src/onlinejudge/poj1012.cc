// http://poj.org/problem?id=1012
#include <iostream>

#include "poj1012.hpp"
using namespace std;

int ans[14];
int k;

int main()
{
  ans[0] = 0;
  Solve solve;
  // 离线求解
  for (int i = 1; i < 14; i++)
  {
    ans[i] = solve.Survivor(i);
  }

  while (cin >> k, k)
  {
    cout << ans[k] << endl;
  }
  return 0;
}
