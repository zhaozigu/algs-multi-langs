// http://poj.org/problem?id=1012
#include <iostream>
using namespace std;

int ans[14];
int k;

int Solve(int k)
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

int main()
{
  ans[0] = 0;
  // 离线求解
  for (int i = 1; i < 14; i++)
  {
    ans[i] = Solve(i);
  }

  while (cin >> k, k)
  {
    cout << ans[k] << endl;
  }
  return 0;
}
