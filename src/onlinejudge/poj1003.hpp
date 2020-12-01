#pragma once

const int kMaxN = 300;
const double delta = 1e-8;

class Solve
{
public:
  Solve()
  {
    len[0] = 0.0;
    for (total = 1; zero(len[total - 1] - 5.20) < 0; total++)
    {
      len[total] = len[total - 1] + 1.0 / (total + 1.00);
    }
  }

  int GetCardNum(double x)
  {
    int l = 0, r = total;
    while (l + 1 < r)
    {
      int mid = (l + r) / 2;
      if (zero(len[mid] - x) < 0)
      {
        l = mid;
      }
      else
      {
        r = mid;
      }
    }
    return r;
  }

  static int zero(double x)
  {
    if (x < -delta)
    {
      return -1;
    }
    return x > delta;
  }

  int GetTotal()
  {
    return total;
  }

private:
  double len[kMaxN];
  int total;
};
