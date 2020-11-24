// http://poj.org/problem?id=1258
#include <iostream>

#include "poj1258.hpp"

using namespace std;
int n;

int main()
{
  while (cin >> n && n)
  {
    Solve solve(n);

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> solve[i][j];
      }
    }
    cout << solve.Prim() << endl;
  }
  return 0;
}