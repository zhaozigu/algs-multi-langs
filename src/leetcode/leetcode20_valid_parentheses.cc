// https://leetcode-cn.com/problems/valid-parentheses/
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    stack<char> t;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{')
      {
        t.push(s[i]);
      }
      else if (s[i] == ')')
      {
        if (i == 0 || t.empty() || t.top() != '(')
        {
          return false;
        }
        t.pop();
      }
      else if (s[i] == ']')
      {
        if (i == 0 || t.empty() || t.top() != '[')
        {
          return false;
        }
        t.pop();
      }
      else if (s[i] == '}')
      {
        if (i == 0 || t.empty() || t.top() != '{')
        {
          return false;
        }
        t.pop();
      }
    }
    return t.empty();
  }
};

#include "gtest/gtest.h"

TEST(leetcode20, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_TRUE(solution.isValid("()"));
}

TEST(leetcode20, sampleInputByProblem2)
{
  Solution solution;
  ASSERT_TRUE(solution.isValid("()[]{}"));
}

TEST(leetcode20, sampleInputByProblem3)
{
  Solution solution;
  ASSERT_FALSE(solution.isValid("(]"));
}

TEST(leetcode20, sampleInputByProblem4)
{
  Solution solution;
  ASSERT_FALSE(solution.isValid("([)]"));
}

TEST(leetcode20, sampleInputByProblem5)
{
  Solution solution;
  ASSERT_TRUE(solution.isValid("{[]}"));
}
