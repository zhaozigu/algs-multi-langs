#pragma once

class Solve
{
public:
  Solve() : sum(0.0), count(0) {}

  void Add(double num)
  {
    sum += num;
    ++count;
  }

  double GetAvg()
  {
    return sum / count;
  }

private:
  double sum;
  int count;
};
