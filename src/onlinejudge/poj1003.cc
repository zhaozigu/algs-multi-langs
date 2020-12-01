// http://poj.org/problem?id=1003
#include <iostream>
using namespace std;
// 提交代码记得拷贝代码
#include "poj1003.hpp"

int main()
{
  Solve solve;
  double x;
  while (cin >> x, Solve::zero(x))
  {
    cout << solve.GetCardNum(x) << " card(s)" << endl;
  }
  return 0;
}