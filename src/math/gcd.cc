/// 最大公约数算法（欧几里得算法）是第一个算法

int gcd(int m, int n)
{
  return n == 0 ? m : gcd(n, m % n);
}

#include "gtest/gtest.h"

TEST(testgcd, CoprimeIntegers)
{
  ASSERT_EQ(1, gcd(1, 3));
}

TEST(testgcd, RoutineTest)
{
  ASSERT_EQ(2, gcd(2, 4));
}
