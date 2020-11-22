#include "benchmark/benchmark.h"

using ll = long long;

ll fib(int n)
{
  return (n < 2) ? 1 : fib(n - 1) + fib(n - 2);
}

int fib_c(int n)
{
  int f = 1, g = 1;

  if (n < 2)
  {
    return 1;
  }

  for (int i = 1; i < n; i++)
  {
    g = f + g; // a_n
    f = g - f; // a_n - a_{n-2} = a_{n-1}
  }

  return g;
}

static void BM_FibRecursion(benchmark::State &state)
{
  for (auto _ : state)
    fib(30);
}

BENCHMARK(BM_FibRecursion);

static void BM_FibIteration(benchmark::State &state)
{
  for (auto _ : state)
    fib_c(30);
}

BENCHMARK(BM_FibIteration);
