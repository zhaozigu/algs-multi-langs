// https://leetcode-cn.com/problems/swap-nodes-in-pairs/
#include "linklist.hpp"

class Solution
{
public:
  ListNode *swapPairs(ListNode *head)
  {
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *temp = dummyHead;
    while (temp->next != nullptr && temp->next->next != nullptr)
    {
      ListNode *node1 = temp->next;
      ListNode *node2 = temp->next->next;
      temp->next = node2;
      node1->next = node2->next;
      node2->next = node1;
      temp = node1;
    }
    return dummyHead->next;
  }
};

#include "gtest/gtest.h"
#include <vector>

using namespace std;

TEST(treenode, sampleInputByProblem1)
{
  ListNode root(1);
  vector<int> ins = {2, 3, 4};
  vector<int> out = {2, 1, 4, 3};
  Solution solution;
  ASSERT_EQ(out, LinkToArray(solution.swapPairs(PushBackList(&root, ins))));
  DestroyLinkList(&root);
}

TEST(treenode, sampleInputByProblem2)
{
  ListNode root;
  vector<int> out = {0};
  Solution solution;
  ASSERT_EQ(out, LinkToArray(solution.swapPairs(&root)));
  DestroyLinkList(&root);
}

TEST(treenode, sampleInputByProblem3)
{
  ListNode root = {1};
  vector<int> out = {1};
  Solution solution;
  ASSERT_EQ(out, LinkToArray(solution.swapPairs(&root)));
  DestroyLinkList(&root);
}