// http://poj.org/problem?id=1005
#include <iostream>

#include "poj1005.hpp"

using namespace std;

int main()
{
  int n;
  cin >> n;
  Solve solve;
  // 笛卡尔坐标
  float x, y;

  for (int i = 1; i <= n; i++)
  {
    cin >> x >> y;
    cout << "Property " << i
         << ": This property will begin eroding in year "
         << solve.Calc(x, y) << ".\n";
  }
  cout << "END OF OUTPUT.\n";
  return 0;
}
