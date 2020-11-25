#pragma once

class Solve
{
public:
  Solve(int n_) : n(n_), p2(1), p3(1), p5(1), uglys(new int[n_ + 1])
  {
    uglys[1] = 1;
    solve();
  }

  ~Solve()
  {
    delete[] uglys;
  }

  int operator[](size_t x)
  {
    return uglys[x];
  }

private:
  // 返回三个数的最小值
  int ThreeMin(int a, int b, int c)
  {
    int min = a < b ? a : b;
    min = min < c ? min : c;
    return min;
  }

  void solve()
  {
    for (int i = 2; i <= n; i++)
    {
      int v2 = uglys[p2] * 2;
      int v3 = uglys[p3] * 3;
      int v5 = uglys[p5] * 5;
      uglys[i] = ThreeMin(v2, v3, v5);

      // 使用最小那个ugly number的下标加1
      if (uglys[i] == v2)
        p2++;
      if (uglys[i] == v3)
        p3++;
      if (uglys[i] == v5)
        p5++;
    }
  }

  int n;
  int p2, p3, p5;
  int *uglys;
};
