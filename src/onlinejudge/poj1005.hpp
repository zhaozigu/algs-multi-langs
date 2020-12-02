#pragma once
#include <cmath>

const double kPI = 3.14159265;

class Solve
{
public:
  int Calc(float x, float y)
  {
    double calc = (x * x + y * y) * kPI / 2 / 50;
    // 要使用上取整ceil，不能使用下取整floor
    return ceil(calc);
  }
};
