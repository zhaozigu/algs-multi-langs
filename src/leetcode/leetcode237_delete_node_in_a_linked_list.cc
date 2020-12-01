// https://leetcode-cn.com/problems/delete-node-in-a-linked-List/
#include <algorithm>
using namespace std;
#include "linklist.hpp"

class Solution
{
public:
  void deleteNode(ListNode *node)
  {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};

#include "gtest/gtest.h"
#include <vector>
using namespace std;

TEST(leetcode237, sampleInputByProblem)
{
  Solution solution;
  ListNode root(4);
  vector<int> in = {5, 1, 9};
  vector<int> out = {4, 1, 9};
  solution.deleteNode(&*PushBackList(&root, in)->next);
  ASSERT_EQ(out, LinkToArray(&root));
}

TEST(leetcode237, sampleInputByProblem1)
{
  Solution solution;
  ListNode root(4);
  vector<int> in = {5, 1, 9};
  vector<int> out = {4, 5, 9};
  solution.deleteNode(&*PushBackList(&root, in)->next->next);
  ASSERT_EQ(out, LinkToArray(&root));
}