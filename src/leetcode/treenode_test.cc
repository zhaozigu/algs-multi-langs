#include "gtest/gtest.h"
#include <memory>
using namespace ::testing;
using namespace std;
#include "treenode.hpp"

TEST(treenode, BuildTreeFromHeapFromRoot)
{
  HeapTree nodes = {TNode(3)};
  ASSERT_EQ(3, BuildTree(nodes)->val);
}

TEST(treenode, BuildTreeFromHeadFromThreeElements)
{
  HeapTree nodes = {TNode(3), TNode(9), TNode(20)};

  ASSERT_EQ(3, BuildTree(nodes)->val);
  ASSERT_EQ(9, BuildTree(nodes)->left->val);
  ASSERT_EQ(20, BuildTree(nodes)->right->val);
}

TEST(treenode, BuildTreeFromHeadIncludeNullptr)
{
  HeapTree nodes = {
      TNode(3),
      TNode(9),
      TNode(20),
      nullptr,
      nullptr,
      TNode(15),
      TNode(7),
  };

  ASSERT_EQ(3, BuildTree(nodes)->val);
  ASSERT_EQ(nullptr, BuildTree(nodes)->left->left);
  ASSERT_EQ(nullptr, BuildTree(nodes)->left->right);
  ASSERT_EQ(15, BuildTree(nodes)->right->left->val);
}
