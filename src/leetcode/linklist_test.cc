#include "gtest/gtest.h"
#include <vector>
using namespace ::testing;
using namespace std;
#include "linklist.hpp"

TEST(treenode, BuildLinkedListByOneElement)
{
  ListNode root(1);
  vector<int> ins = {2};
  vector<int> out = {1, 2};
  ASSERT_EQ(out, LinkToArray(PushBackList(&root, ins)));
  DestroyLinkList(&root);
}

TEST(treenode, BuildLinkedListByMultiElements)
{
  ListNode root(1);
  vector<int> ins = {2, 3, 4, 5};
  vector<int> out = {1, 2, 3, 4, 5};
  ASSERT_EQ(out, LinkToArray(PushBackList(&root, ins)));

  DestroyLinkList(&root);
}

TEST(treenode, BuildLinkedListByDefaultConstructFunction)
{
  ListNode root;
  ASSERT_EQ(0, root.val);
  ASSERT_EQ(nullptr, root.next);
  DestroyLinkList(&root);
}