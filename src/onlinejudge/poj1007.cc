// http://poj.org/problem?id=1007
#include <iostream>
#include <string>
#include <algorithm>

#include "poj1007.hpp"

using namespace std;
// 使用C++STL中的string，不需要规定n
const int kMaxM = 101;

int n, m;

typedef struct DNAInfo_
{
  string s; // DNA串
  int x;    // 逆序数
} DNAInfo;

DNAInfo a[kMaxM];

bool cmp(const DNAInfo &a, const DNAInfo &b)
{
  return a.x < b.x;
}

int main()
{
  cin >> n >> m;

  Solve solve;

  for (int i = 0; i < m; i++)
  {
    cin >> a[i].s;
    a[i].x = solve.Stat(a[i].s);
  }

  sort(a, a + m, cmp);

  for (int i = 0; i < m; i++)
  {
    cout << a[i].s << endl;
  }
  return 0;
}
