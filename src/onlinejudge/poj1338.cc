// http://poj.org/problem?id=1338
#include <iostream>

#include "poj1338.hpp"

using namespace std;
int main()
{
  // 离线计算前1500个
  Solve solve(1500);
  int n;
  while (cin >> n, n != 0)
  {
    cout << solve[n] << endl;
  }

  return 0;
}