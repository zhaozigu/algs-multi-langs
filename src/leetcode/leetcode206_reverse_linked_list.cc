// https://leetcode-cn.com/problems/reverse-linked-list/
#include "linklist.hpp"
using namespace std;

class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    if (head == nullptr)
    {
      return head;
    }

    ListNode *cur = head, *pre = nullptr, *temp = nullptr;
    while (cur != nullptr)
    {
      temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = temp;
    }
    return pre;
  }
};

#include "gtest/gtest.h"

TEST(leetcode206, sampleInputByProblem)
{
  Solution solution;
  ListNode root(1);
  vector<int> in = {2, 3, 4, 5};
  vector<int> out = {5, 4, 3, 2, 1};
  ASSERT_EQ(out, LinkToArray(solution.reverseList(PushBackList(&root, in))));
  DestroyLinkList(&root);
}