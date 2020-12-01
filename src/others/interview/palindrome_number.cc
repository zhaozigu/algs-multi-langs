#include <limits>
#include <cmath>
using namespace std;

bool is_palindrome(int n)
{
  if (n == numeric_limits<int>::min())
  {
    return false;
  }
  n = abs(n + 0.0);
  int help = 1;
  // 防止溢出
  while (n / help >= 10)
  {
    help *= 10;
  }

  while (n != 0)
  {
    if (n / help != n % 10)
    {
      return false;
    }
    n = (n % help) / 10;
    help /= 100;
  }
  return true;
}

#include "gtest/gtest.h"

TEST(testIsPalindrome, IsPalindromeTrue)
{
  ASSERT_TRUE(is_palindrome(22));
  ASSERT_TRUE(is_palindrome(121));
  ASSERT_TRUE(is_palindrome(-121));
  ASSERT_TRUE(is_palindrome(-22));
}

TEST(testIsPalindrome, IsPalindromeFalse)
{
  ASSERT_FALSE(is_palindrome(numeric_limits<int>::min()));
  ASSERT_FALSE(is_palindrome(1241));
  ASSERT_FALSE(is_palindrome(21));
  ASSERT_FALSE(is_palindrome(-12));
}