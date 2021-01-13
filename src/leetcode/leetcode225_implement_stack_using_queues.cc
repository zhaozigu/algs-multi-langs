// https://leetcode-cn.com/problems/implement-stack-using-queues
#include <queue>
using namespace std;

class MyStack
{
public:
  /** Initialize your data structure here. */
  queue<int> q1, q2;
  MyStack()
  {
  }

  /** Push element x onto stack. */
  void push(int x)
  {
    q1.push(x);
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop()
  {
    while (q1.size() != 1)
    {
      int t = q1.front();
      q1.pop();
      q2.push(t);
    }
    int res = q1.front();
    q1.pop();
    while (!q2.empty())
    {
      int t = q2.front();
      q2.pop();
      q1.push(t);
    }

    return res;
  }

  /** Get the top element. */
  int top()
  {
    return q1.back();
  }

  /** Returns whether the stack is empty. */
  bool empty()
  {
    return q1.empty();
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
#include "gtest/gtest.h"

TEST(leetcode225, sampleInputByProblem)
{
  MyStack myStack;
  myStack.push(1);
  myStack.push(2);
  ASSERT_EQ(2, myStack.top());   // return 2
  ASSERT_EQ(2, myStack.pop());   // return 2
  ASSERT_FALSE(myStack.empty()); // return False
}