/// 设计一个 getMin 功能的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作。
/// 要求：
///  - pop、push、getMin 操作的时间复杂度都是 O(1)
///  - 设计的栈类型可以使用现成的栈结构

#include <stack>
#include <vector>
#include <stdexcept>
using namespace std;

/// 下面方案都基于双栈设计，一个用来存储数据 `stack_data，一个用来保存数据的最小值 `stack_min`

class GetMinStack
{
public:
  void push_batch(const vector<int> &inputs)
  {
    for (auto &a : inputs)
    {
      push(a);
    }
  }

  void push(int data)
  {
    stack_data.push(data);
    if (stack_min.empty())
    {
      stack_min.push(data);
    }
    else if (data < stack_min.top())
    {
      stack_min.push(data);
    }
    else
    {
      stack_min.push(stack_min.top());
    }
  }

  int pop()
  {
    if (stack_data.empty())
    {
      throw out_of_range("stack_data is empty!");
    }
    int top = stack_data.top();
    stack_data.pop();
    stack_min.pop();
    return top;
  }

  int getMin()
  {
    if (stack_min.empty())
    {
      throw out_of_range("stack_min is empty!");
    }
    return stack_min.top();
  }

private:
  stack<int> stack_data;
  stack<int> stack_min;
};

////////////////////// TEST //////////////////////

#include "gtest/gtest.h"

TEST(testGetMinStack, sampleInputOneElement)
{
  GetMinStack getmin;
  getmin.push(1);
  ASSERT_EQ(1, getmin.getMin());
}

TEST(testGetMinStack, sampleInputTwoElements)
{
  GetMinStack getmin;
  getmin.push(2);
  getmin.push(1);
  ASSERT_EQ(1, getmin.getMin());
  getmin.pop();
  ASSERT_EQ(2, getmin.getMin());
}

TEST(testGetMinStack, sampleInputMultiElements)
{
  GetMinStack getmin;
  vector<int> ins = {3, 4, 5, 1, 2, 1};
  getmin.push_batch(ins);

  ASSERT_EQ(1, getmin.getMin());
  getmin.pop();
  ASSERT_EQ(1, getmin.getMin());
  getmin.pop();
  ASSERT_EQ(1, getmin.getMin());
  getmin.pop();
  ASSERT_EQ(3, getmin.getMin());
  getmin.pop();
  ASSERT_EQ(3, getmin.getMin());
  getmin.pop();
  ASSERT_EQ(3, getmin.getMin());
}

TEST(testGetMinStack, nullValueTest)
{
  GetMinStack getmin;
  ASSERT_THROW(getmin.getMin(), out_of_range);
  ASSERT_THROW(getmin.pop(), out_of_range);
}