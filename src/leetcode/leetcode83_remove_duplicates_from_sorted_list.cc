// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
using namespace std;
#include "linklist.hpp"

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }
    ListNode *p = head;
    while (p != nullptr && p->next != nullptr)
    {
      while (p->next != nullptr && p->next->val == p->val)
      {
        p->next = p->next->next;
      }
      p = p->next;
    }
    return head;
  }
};

#include "gtest/gtest.h"

TEST(leetcode83, sampleInputByProblem1)
{
  Solution solution;
  ListNode root(1);
  vector<int> in = {1, 2};
  vector<int> out = {1, 2};
  solution.deleteDuplicates(PushBackList(&root, in));
  ASSERT_EQ(out, LinkToArray(&root));
  DestroyLinkList(&root);
}

TEST(leetcode83, sampleInputByProblem2)
{
  Solution solution;
  ListNode root(1);
  vector<int> in = {1, 2, 3, 3};
  vector<int> out = {1, 2, 3};
  solution.deleteDuplicates(PushBackList(&root, in));
  ASSERT_EQ(out, LinkToArray(&root));
  DestroyLinkList(&root);
}