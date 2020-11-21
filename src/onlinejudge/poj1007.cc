// http://poj.org/problem?id=1007
#include <iostream>
#include <string>
#include <algorithm>

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

void Swap(char &a, char &b)
{
  char temp = a;
  a = b;
  b = temp;
}

// 返回逆序数
int Stat(string s)
{
  int count = 0;
  int len = s.length();
  // 冒泡排序
  for (int i = 0; i < len - 1; i++)
  {
    for (int j = 0; j < len - 1 - i; j++)
    {
      if (s[j] > s[j + 1])
      {
        Swap(s[j], s[j + 1]);
        ++count;
      }
    }
  }
  return count;
}

bool cmp(const DNAInfo &a, const DNAInfo &b)
{
  return a.x < b.x;
}

int main()
{
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    cin >> a[i].s;
    a[i].x = Stat(a[i].s);
  }

  sort(a, a + m, cmp);

  for (int i = 0; i < m; i++)
  {
    cout << a[i].s << endl;
  }
  return 0;
}
